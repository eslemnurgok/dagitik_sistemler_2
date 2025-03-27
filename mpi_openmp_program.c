#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <mpi.h>

#define DATA_SIZE 1000000

void process_data(int rank, int size) {
    int chunk = DATA_SIZE / size;
    int start = rank * chunk;
    int end = start + chunk;

    double sum = 0.0;
    
    #pragma omp parallel for reduction(+:sum)
    for (int i = start; i < end; i++) {
        sum += i * 1.0;
    }

    printf("Rank %d: Partial sum = %f\n", rank, sum);

    double global_sum;
    MPI_Reduce(&sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Total Sum = %f\n", global_sum);
    }
}

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    process_data(rank, size);

    MPI_Finalize();
    return 0;
}

