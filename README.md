# Tugas Besar 2 - Distance Vector Simulation
Oleh kelompok 6 - Verrero:
- 13515011 - Reinhard Benjamin Linardi
- 13515047 - Verena Severina
- 13515107 - Roland Hartanto

## Petunjuk Penggunaan Program
Buka terminal/command prompt pada direktori root (direktori yang terdapat Makefile di dalamnya) dan ketikkan `make` untuk melakukan kompilasi dan instalasi. File executable akan terbentuk pada direktori root. Program dapat digunakan dengan menjalankan file executable tersebut.

## Cara Kerja Program
**1. Simulasi Node**

Tabel routing disimulasikan dengan matriks ketetanggaan dengan elemen [1000][1000]. Elemen tabel adalah tuple yang disusun dengan membuat struktur data yang terdiri dari jarak, next hop, dan status ketetanggaan sebuah node dengan node yang lainnya.

**2. Simulasi Pengiriman Pesan**

Pada awal program, setelah menerima masukan, dilakukan inisialisasi tabel routing sesuai dengan masukan. Pada setiap masukan skenario, dilakukan pembaharuan tabel routing untuk node yang menerima informasi. Pembaharuan dilakukan untuk jarak dan next hop.

Terdapat tiga kasus yang dapat terjadi saat pembaharuan tabel routing dilakukan. Ketiga kasus tersebut adalah sebagai berikut.
- Node penerima belum mengetahui apabila node tersebut dapat menjangkau node j, tetapi node pengirim sudah mengetahui apabila node tersebut dapat menjangkau node j. Untuk kasus ini, jarak node penerima dengan node j adalah jarak node pengirim dengan node j ditambah dengan 1. Next hop pada node penerima untuk node j adalah node pengirim.
- Node pengirim dan penerima dapat menjangkau node j, tetapi jika melewati node pengirim jaraknya lebih kecil. Untuk kasus ini, jarak node penerima adalah jarak node pengirim ditambah dengan 1. Next hop pada node penerima untuk node j adalah node pengirim.
- Node pengirim dan penerima dapat menjangkau node j dan jarak keduanya sama. Untuk kasus ini, next hop pada node penerima untuk node j adalah node dengan nomor terkecil.

## Pembagian Tugas
- Reinhard membuat algoritma program utama.
- Roland membuat struktur data node.
- Verena melakukan pengujian terhadap program.

## Jawaban Pertanyaan
**1. Perbedaan dari routing protocol distance-vector dan link state**

Perbedaan dari protokol distance vector dan link state adalah dari informasi yang dikirim saat routing. Pada distance vector setiap node saling bertukar tabel (vektor) jarak ke node lainnya secara periodik. Apabila ditemukan jalur yang lebih cepat, maka tabel akan diupdate. Setiap node mengelola tabel jarak antara node tersebut dengan node lainnya. Setiap node tidak mengetahui topologi jaringan keseluruhan.

Pada protokol link state, setiap node akan menerima informasi link cost. Kemudian, masing-masing node dapat menghitung jalan terpendek dari node tersebut ke setiap node yang lain. Setiap node mengirimkan informasi dengan flooding ke seluruh link yang dimilikinya. Jika sebuah node menerima informasi, informasi tersebut akan diteruskan ke seluruh link lain yang dimilikinya. Oleh sebab itu, setiap node mengetahui topologi jaringan keseluruhan.

Protokol yang lebih baik digunakan adalah protokol link state. Protokol Link state lebih efisien bila dibandingkan dengan distance vector sebab suatu node mengetahui topologi jaringan. Selain itu, pada protokol link state, setiap node dapat mengetahui jalur terpendek ke node-node lainnya.

**2. Pada implementasinya saat ini manakah yang lebih banyak digunakan, distance-vector atau link state? Mengapa?**

Pada implementasinya, sekarang ini yang paling banyak digunakan adalah Link State Routing Protocol, terutama OSPF. Hal ini disebabkan karena OSPF dapat dioperasikan pada berbagai vendor berbeda. Link State Routing Protocol juga cocok untuk digunakan pada suatu perusahaan besar karena langsung mengirimkan informasi ke semua router yang ada pada jaringan. Pengiriman dengan Link State lebih efisien sebab setiap router mengetahui topologi jaringan dan dapat mengirim pesan melalui jalan terdekat ke tujuannya. Namun, pada dasarnya, baik Distance Vector maupun Link State masih sangat banyak digunakan karena keduanya memiliki kelebihan masing-masing yang dapat disesuaikan dengan kebutuhan orang yang menggunakannya. Jika Link State cocok untuk digunakan pada perusahaan yang besar, maka Distance Vector cocok untuk digunakan perusahaan yang kecil. Hal ini disebabkan karena Distance Vector menyampaikan informasi ke tetangga terdekatnya.