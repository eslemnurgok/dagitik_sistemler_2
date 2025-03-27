# Ubuntu tabanlı bir görüntü kullanıyoruz
FROM ubuntu:22.04  

# Gerekli paketleri güncelliyoruz
RUN apt-get update && apt-get install -y \
    mpich \
    libomp-dev \
    build-essential  

# Çalışma dizinini oluşturuyoruz
WORKDIR /app  

# Paralel programlama kodunu konteyner içine kopyalıyoruz
COPY mpi_openmp_program.c /app/mpi_openmp_program.c  

# Programı derliyoruz (Hem MPI hem OpenMP kullanarak)
RUN mpicc -fopenmp mpi_openmp_program.c -o mpi_openmp_program  

CMD ["mpirun", "-np", "4", "./mpi_openmp_program"]
