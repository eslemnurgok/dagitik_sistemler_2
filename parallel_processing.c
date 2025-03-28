#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>

#define N 1000000  // Büyük veri boyutu

void hesapla(int *veri, int boyut) {
    #pragma omp parallel for
    for (int i = 0; i < boyut; i++) {
        veri[i] *= 2;  // Örnek işlem: Veriyi 2 ile çarp
    }
}

int main(int argc, char **argv) {
    int rank, size;
    MPI_Init(&argc, &argv);  // MPI başlat
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Rank al (düğüm kimliği)
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Toplam düğüm sayısı

    int local_size = N / size;  // Her düğüme düşen veri miktarı
    int *local_data = (int*)malloc(local_size * sizeof(int));

    // OpenMP ile paralel veri üretimi
    #pragma omp parallel for
    for (int i = 0; i < local_size; i++) {
        local_data[i] = rank * local_size + i;
    }

    // OpenMP ile veriyi işleyelim
    hesapla(local_data, local_size);

    // Sonuçları ana düğüme gönder
    int *global_data = NULL;
    if (rank == 0) {
        global_data = (int*)malloc(N * sizeof(int));
    }

    MPI_Gather(local_data, local_size, MPI_INT, global_data, local_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Ana düğüm (rank 0) çıktıyı alır
    if (rank == 0) {
        printf("Hesaplama tamamlandı! İlk 10 sonuç:\n");
        for (int i = 0; i < 10; i++) {
            printf("%d ", global_data[i]);
        }
        printf("\n");

        free(global_data);
    }

    free(local_data);
    MPI_Finalize();  // MPI'yi kapat
    return 0;
}
