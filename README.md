# **Tugas Intro to Data Structure** #

Asssigment Session 1-2

## **Hotel-del-Jojo** ##
- - - -
Selamat datang di Hotel-del-Jojo, hotel untuk orang yang sudah mati.
Siapapun yang telah mati dapat tinggal di hotel ini.

Kamu adalah admin sekaligus resepsionis yang melakukan data management pada hotel ini.

Berikut adalah beberapa hal yang perlu kamu ketahui:
1. Hotel dapat menampung maksimal 255 orang.
2. Hotel dapat memiliki maksimal 10 tipe kamar.
3. Untuk bisa mendaftar di hotel ini, dibutuhkan beberapa data, diantaranya:
    1. Nama
    2. Umur
    3. Penyebab Kematian
    4. Tempat Peristirahatan Terakhir
    5. Tahun Kematian
    6. Tipe Ruangan yang diinginkan
4. Pengorganisasian Data dilakukan berdasarkan dua hal:
    1. ID dari setiap Customer
    2. ID dari setiap Ruangan

Berikut rincian untuk tipe Ruangan yang sudah ada:
|No|ID Kamar| Jenis Kamar | Harga Kamar |
|:--:|:---:|:---:|:---|
|1|R001|Pantai|₩3,000,000|
|2|R002|Rooftop|₩4,500,000|
|3|R003|Taman|₩5,000,000|
|4|R004|Bar|₩1,250,000|

**Silahkan mulai bekerja!**
<br></br>

## **Breakdown**
- - - -
<details style="font-size: 14px">
<summary style="font-size: 18px"><b>main.cpp</b></summary>
<h3>Pada bagian main.cpp terdapat beberapa fungsi:</h3>

* Deklarasi struct Customer dan Type untuk data Customer dan tipe kamar
```c++
struct Customer{
    int customer_id;
    char customer_name[255];
    int customer_age;
    char customer_cause_of_death[255];
    char customer_resting_place[255];
    int customer_died_year;
    int room_type_id;
};
struct RoomType{
    int room_type_id;
    char room_type_name[255];
    long unsigned int room_type_price;
};
```

* `import_data_from_file()` 
<p style="margin-left:41px">
berfungsi untuk memasukkan data dari file ke dalam array of struct <code>Customer</code> serta memasukkan data dari file ke dalam array of struct <code>RoomType</code> yang menspesifikasikan ada berapa tipe Ruangan.
</p>

* `printExitMessage()` 
<p style="margin-left:41px">berfungsi untuk mengeluarkan message dari <code>asciiart.txt</code> sebagai berikut:</p>

```
  _   _       _       _       _      _     ___       _       
 | | | |     | |     | |     | |    | |   |_  |     (_)      
 | |_| | ___ | |_ ___| |   __| | ___| |     | | ___  _  ___  
 |  _  |/ _ \| __/ _ \ |  / _` |/ _ \ |     | |/ _ \| |/ _ \ 
 | | | | (_) | ||  __/ | | (_| |  __/ | /\__/ / (_) | | (_) |
 \_| |_/\___/ \__\___|_|  \__,_|\___|_| \____/ \___/| |\___/ 
                                                   _/ |      
                                                  |__/       
 __   __                    _   
 \ \ / /                   | |  
  \ V /  _____   _____ _ __| |_ 
  /   \ / _ \ \ / / _ \ '__| __|
 / /^\ \ (_) \ V /  __/ |  | |_ 
 \/   \/\___/ \_/ \___|_|   \__|

Goodbye!
```

* `menu()` berfungsi untuk menampilkan menu berikut:
    ```
    Hotel del Jojo
    1. Add new customer
    2. Read data
    3. Update data
    4. Remove data
    5. Exit
    ```

* Lalu ada fungsi `main()` dimana program dijalankan dengan sequence sebagai berikut:
    - Menunjukkan `menu()`
    - Meminta User memilih Menu
    - Memanggil fungsi dari `customer.h` sesuai dengan menu
    - Jika memilih exit, maka tampilkan `printExitMessage()` dan keluar program.
</details>

---

<details>
<summary style = "font-size: 18px"><b>customer.h</b></summary>

<p style="font-size: 15px">
Pada bagian ini, fungsi - fungsi utama dari program CRUD terletak,
diantaranya:</p>
<ul>
<li><code>create()</code></li>

<p style="margin-left:0px; text-align:justify">
Fungsi ini bertujuan untuk menerima customer dari <strong>hotel-del-jojo</strong> yang baru. User akan diminta untuk memasukkan info - info yang dibutuhkan.
Secara garis besar, ada 3 bagian dari fungsi ini:
</p>
    <ol>
<li>Input Data</li>
Proses pemasukkan data meliputi 6 bagian data:
    <ul>
    <li>Nama</li>
    Nama yang di-input harus dalam huruf kecil (lowercase)
    <li>Umur</li>
    Umur yang diperbolehkan hanya umur 0 (bayi) hingga umur 100(lansia), selain dari itu tidak diperbolehkan untuk masuk
    <li>Penyebab Kematian</li>
    Penyebab kematian dari tamu yang mendaftar, tidak boleh melebihi 255 karakter
    <li>Tempat Peristirahatan Terakhir</li>
    Tempat peristirahatan terakhir dari badan fisik yang ada di dunia, tidak boleh melebihi 255 karakter
    <li>Tahun Kematian</li>
    <i>Self-Explanatory</i>
    <li>Tipe kamar yang ingin dipesan</li>
    Memilih kamar yang diinginkan oleh tamu, hanya boleh memilih dari kamar yang ada.
    Tidak bisa memilih kamar dengan tipe custom.
    <br>Hanya ada 4 jenis kamar, yakni:</br>
    <ol>
    <li>Pantai</li>
    <li>Rooftop</li>
    <li>Taman</li>
    <li>Bar</li>
    </ol>
    </ul>
<li>Memasukkan Data ke array</li>
Masing - masing data yang sudah di input, dimasukkan satu per-satu ke dalam array yang berisi customer-customer yang sedang tinggal di <strong>hotel-del-jojo</strong>.
<br>Untuk customer id, menambahkan kode customer terakhir yang check-in ke dalam hotel</br>

<li>Menulis Data pada File <code>customer_data.txt</code></li>
Pada bagian ini, file <code>customer_data.txt</code> dibuka dan menulis dan menambahkan data customer yang baru saja check-in.
    </ol>

Contoh:
```
Nama (lowercase letters): Budi
Nama (lowercase letters): budi
Age (0-100): 500
Age (0-100): -5
Age (0-100): 30
Cause of Death (max 255 letters): Accident
Resting Place (max 255 letters): Graveyard
Room Type (Pantai, Rooftop, Taman, Bar): Gunung
Room Type (Pantai, Rooftop, Taman, Bar): Bar

Welcome to Hotel del Jojo!
```

<br>
<li><code>read()</code></li>
Fungsi ini bertujuan untuk men-display data - data Customer yang sedang tinggal dalam <strong>hotel-del-jojo</strong>
Bekerja dengan cara men-<i>display</i> data yang ada dari array berisi customer - customer.
</br>

Contoh:
|   | ID   | Name  | Age | Room   |
|---|------|-------|-----|--------|
| 1 | C001 | Dodi  | 18  | Pantai |
| 2 | C002 | Anto  | 21  | Pantai |
| 3 | C003 | Aseng | 32  | Taman  |
| 4 | C004 | Budi  | 30  | Bar    |

<br>
<li><code>update()</code></li>
Fungsi ini bertujuan untuk mengubah data customer, jika ingin berpindah tipe kamar.
<br>Secara garis besar dibagi menjadi 3 bagian:</br>
<ol>
<li>Input perubahan data</li>
Pertama, menampilkan data seluruh Customer yang ada di hotel-del-jojo.
<br>Kedua, meminta input ID dari customer yang ingin diubah datanya. Pastikan ID nya ada.</br>
Ketiga, meminta input tipe ruangan baru yang diinginkan.
Terdiri dari keempat tipe ruangan yang sama seperti sebelumnya.

<li>Mengganti data pada array</li>
Mengganti tipe ruangan tamu dengan ID yang dimaksud pada array berisi data customer.

<li>Mengganti data pada file</li>
Menulis ulang data file dari data - data customer yang ada di array.

<li>Prompt Update data</li>
Menanyakan pengguna apakah ingin melihat data yang sudah di <i>update</i>
Apabila ya, tunjukkan data. Apabila tidak, kembali ke menu utama.

</ol>

</br>

|   | ID   | Name  | Age | Room   |
|---|------|-------|-----|--------|
| 1 | C001 | Dodi  | 18  | Pantai |
| 2 | C002 | Anto  | 21  | Pantai |
| 3 | C003 | Aseng | 32  | Taman  |
| 4 | C004 | Budi  | 30  | Bar    |

```
Enter ID: C009
Enter ID: C003
Insert New Room (Pantai, Rooftop, Taman, Bar): Pantai
Data Updated for Customer ID C003!
Would you like to see the updated data? [Y\N]: Y
```
|   | ID   | Name  | Age | Room   |
|---|------|-------|-----|--------|
| 1 | C001 | Dodi  | 18  | Pantai |
| 2 | C002 | Anto  | 21  | Pantai |
| 3 | C003 | Aseng | 32  | Taman  |
| 4 | C004 | Budi  | 30  | Pantai |

```Press Enter to Continue_```


<li><code>remove()</code></li>
Fungsi ini bertujuan untuk menghapus data customer baik di file maupun di array.
<br>Secara garis besar dibagi menjadi 3 bagian:</br>
<ol>
<li>Pemilihan data yang ingin dihapus</li>
Pada bagian ini user diminta untuk memasukkan ID dari Customer yang ingin dihilangkan seluruh datanya. Pastikan ID-nya ada.

<li>Penghapusan data pada array</li>
Index dari data customer yang ingin dihapus sudah didapatkan, maka menghapus data pada array yang berisi data customer dengan mengubah status customer menjadi tidak aktif. Status customer dilambangkan dengan id mereka. Apabila customer memiliki id 0, maka dilambangkan tidak aktif. Maka, id customer yang ingin dihapus diubah menjadi 0.

<li>Menghapus data pada file</li>
Menulis ulang data pada file, berdasarkan data yang ada pada array berisi data Customer. Data yang ditulis hanya data dengan status aktif.

<li>Prompt Update data</li>
Menanyakan pengguna apakah ingin melihat data yang sudah di <i>update</i>
Apabila ya, tunjukkan data. Apabila tidak, kembali ke menu utama.

</ol>

Contoh: 
|   | ID   | Name  | Age | Room   |
|---|------|-------|-----|--------|
| 1 | C001 | Dodi  | 18  | Pantai |
| 2 | C002 | Anto  | 21  | Pantai |
| 3 | C003 | Aseng | 32  | Taman  |
| 4 | C004 | Budi  | 30  | Pantai |
```
Enter ID: C009
Enter ID: C003
Customer Data with ID C003 has been deleted!
Would you like to see the updated data? [Y/N]: Y
```
|   | ID   | Name  | Age | Room   |
|---|------|-------|-----|--------|
| 1 | C001 | Dodi  | 18  | Pantai |
| 2 | C002 | Anto  | 21  | Pantai |
| 3 | C004 | Budi  | 30  | Pantai |

</ul>
<br>
<li><code>getInt()</code></li>
Fungsi ini bukan merupakan bagian dari CRUD, namun digunakan pada program.
Fungsi ini berfungsi menerima input dari user untuk angka.
</br>


</details>

