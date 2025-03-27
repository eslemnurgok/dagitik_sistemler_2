Dağıtık Sistemler Projesi

Bu proje, Docker kullanarak birden fazla düğümlü dağıtık mimari kurmayı, MPI ile düğümler arasında büyük veri paylaşımını yapmayı ve OpenMP ile her düğümün kendi içinde çok
çekirdekli paralel işlem yapmasını sağlar. Proje, veri işleme için farklı düğümlerde parçalı hesaplama yapmayı hedefler.

İçerik
Dağıtık Mimariler: Docker ve MPI kullanarak çok düğümlü sistemlerde dağıtık hesaplama.

OpenMP ile Paralel Hesaplama: Her düğümün kendi içinde çok çekirdekli paralel işlem yapması.

Veri Paylaşımı: MPI kullanarak büyük veri setlerinin düğümler arasında paylaşılması.

Veri İşleme: Farklı düğümlerde paralel hesaplamalar yaparak veri işlenmesi.

Gereksinimler
Docker

Docker Compose

MPI (Message Passing Interface)

OpenMP (Open Multi-Processing)

Ubuntu 22.04 (veya uyumlu bir Linux dağıtımı)

Kurulum
1. Docker ve Docker Compose Kurulumu
Eğer Docker yüklü değilse, Docker'ın resmi sitesinden Docker'ı indirip kurun. Docker Compose, genellikle Docker ile birlikte gelir, ancak ayrıca buradan kurulum yapılabilir.

2. Projeyi Klonlayın
Projeyi bilgisayarınıza klonlamak için şu komutu kullanın:


git clone git@github.com:eslemnurgok/dagitik_sistemler_2.git
3. Docker Container'larını Başlatın
Projenin içinde bulunduğunuz dizinde, Docker container'larını başlatmak için şu komutu kullanın:


docker-compose up --build
Bu komut, tüm bağımlılıkları indirip gerekli container'ları oluşturur ve başlatır.

4. Projeyi Çalıştırın
Projeyi başarıyla başlattıktan sonra, paralel hesaplamalar yapılmaya başlanacaktır. Docker container'larında MPI ve OpenMP kullanarak işlemler yürütülecektir.

Proje Yapısı
Dockerfile: Docker image'ını oluşturmak için kullanılan talimatlar.

docker-compose.yml: Docker Compose konfigürasyon dosyası.

mpi_openmp_program.c: MPI ve OpenMP ile yazılmış C programı.

README.md: Proje hakkında bilgi veren dosya.

Katkı
Projeye katkıda bulunmak isterseniz, aşağıdaki adımları takip edebilirsiniz:

Fork yapın.

Yeni bir branch oluşturun: git checkout -b feature/feature-name.

Değişikliklerinizi yapın ve commit edin: git commit -am 'Add new feature'.

Değişikliklerinizi GitHub'a gönderin: git push origin feature/feature-name.

Bir pull request oluşturun.

Lisans
Bu proje MIT Lisansı ile lisanslanmıştır.
