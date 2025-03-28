# OpenMPI ve OpenMP içeren bir temel imaj kullan
FROM ubuntu:latest

# Gerekli bağımlılıkları yükle
RUN apt-get update && apt-get install -y \
    build-essential \
    openmpi-bin \
    libopenmpi-dev \
    libomp-dev

# Çalışma dizini oluştur
WORKDIR /app

# Kod dosyalarını konteynere kopyala
COPY parallel_processing.c .

# Kodu derle (OpenMP ve MPI desteği ile)
RUN mpicc -fopenmp parallel_processing.c -o parallel_processing.out

# Varsayılan komut
CMD ["mpirun", "--allow-run-as-root", "-np", "4", "./parallel_processing.out"]
