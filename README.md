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




MPI ve OpenMP Performans Karşılaştırması

MPI (Message Passing Interface)
MPI, farklı düğümler arasında veri iletimi için kullanılan bir protokoldür. Düğümler arasındaki veri paylaşımı ve senkronizasyonu için kullanılır. Bu, özellikle çok düğümlü sistemlerde büyük veri setlerinin işlenmesinde verimli olmasını sağlar.

Avantajları:
Dağıtık sistemlerde verimli: MPI, farklı makineler arasındaki veri iletişimini yönetir. Bu, çok büyük veri setlerinin farklı düğümler arasında etkili bir şekilde paylaşılmasını sağlar.

Yüksek ölçeklenebilirlik: Çok sayıda düğümün kullanılması gerektiğinde performans kayıpları minimum seviyeye indirilebilir.

Ayrık işleme: MPI, her düğümde bağımsız işleme yapabilen bir model sunar, bu da paralel işlemeyi optimize eder.

Dezavantajları:
İletişim maliyetleri: Düğümler arasındaki veri iletimi, iletişim bant genişliğine ve ağ gecikmesine bağlı olarak performansı etkileyebilir.

Daha karmaşık programlama: MPI programları, iletişim ve senkronizasyon süreçlerini manuel olarak yönetmeyi gerektirir, bu da daha fazla hata riski taşır.

OpenMP (Open Multi-Processing)
OpenMP, çok çekirdekli işlemcilerde paralel işleme yapmayı amaçlayan bir API'dir. OpenMP, bir tek makine içinde paralel işlemeyi optimize eder ve genellikle çok çekirdekli işlemcilerde kullanılır.

Avantajları:
Daha kolay programlama: OpenMP, paralel işlemi kolaylaştırmak için basit direktifler kullanır. Bu, geliştiricinin işini hızlandırır ve paralel işleme sürecini daha erişilebilir kılar.

Düşük iletişim maliyetleri: Tüm işlemciler aynı makine içinde olduğu için, veri iletimi genellikle daha hızlıdır ve daha düşük gecikme süresiyle gerçekleştirilir.

Daha düşük karmaşıklık: OpenMP, paralel işlemeyi ve veri paylaşımını yönetmek için daha az çaba gerektirir.

Dezavantajları:
Sadece çok çekirdekli sistemlerde etkilidir: OpenMP, sadece bir makine üzerinde çok çekirdekli işlemcilerde çalışır. Yani, farklı makineler arasında işlem yapmayı gerektiren durumlarda verimsiz olabilir.

Sınırlı ölçeklenebilirlik: OpenMP, sistemin fiziksel çekirdek sayısıyla sınırlıdır ve büyük ölçekli paralel hesaplamalar için yetersiz olabilir.

Performans Farkları ve Karşılaştırma
Çoklu Düğümler Arasında Veri Paylaşımı:
MPI, çok düğümlü sistemlerde verimli veri paylaşımı sağlar. Düğümler arasındaki iletişim OpenMP'ye göre daha yavaş olsa da, büyük ölçekli dağıtık sistemlerde avantajlıdır.

OpenMP, yalnızca bir makine üzerinde çalıştığı için, düğümler arası iletişim gerektiren durumlarda etkisizdir.

Hesaplama Performansı:
OpenMP, tek bir makinede çok çekirdekli işlemcilerde paralel hesaplamayı optimize eder. Eğer işlemci çok çekirdekli ise, OpenMP daha yüksek performans gösterebilir.

MPI ise, çok sayıda düğüm kullanarak paralel hesaplama yapabilir ve büyük veri setlerini dağıtarak işlem süresini kısaltabilir. Ancak, düğümler arasındaki iletişim ve veri paylaşımının maliyeti göz önünde bulundurulduğunda, performans kaybı yaşanabilir.

Ölçeklenebilirlik:
MPI, daha büyük sistemlerde yüksek ölçeklenebilirlik sunar. Birçok düğüm ekleyerek performansı artırabilir.

OpenMP, fiziksel çekirdek sayısı ile sınırlıdır ve bu nedenle sınırlı ölçeklenebilirlik sunar.

Genel Sonuç:
MPI, büyük ve dağıtık sistemlerdeki projeler için en iyi tercihtir, çünkü birden fazla düğümle veri paylaşımı ve paralel işlem yapabilir. Ancak, yüksek iletişim maliyetleri ve karmaşık programlama gerekebilir.

OpenMP, çok çekirdekli işlemcilerde çalışarak paralel işlem yapar ve daha düşük iletişim maliyetleri sunar. Ancak, sadece tek bir makinede çalışabildiğinden, büyük dağıtık sistemler için uygun değildir.


