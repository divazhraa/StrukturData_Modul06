# <h1 align="center">Laporan Praktikum Modul 6 - SDOUBLY LINKED LIST (BAGIAN PERTAMA)- ... </h1>
<p align="center">[Diva Zahrah Nabila] - [109082500112]</p>

## Unguided 

# Dasar Teori
## A.	Dasar Teori Doubly Linked List
####    Doubly Linked List adalah jenis linked list di mana masing-masing elemennya memiliki dua penunjuk (successor) utama, yaitu penunjuk ke elemen sebelumnya (prev) dan penunjuk ke elemen sesudahnya (next). Struktur ini menggunakan dua buah pointer utama untuk mengontrol list, yakni first yang menunjuk pada elemen pertama dan last yang menunjuk pada elemen terakhir list. Proses operasi dasar seperti pencarian (searching), pengubahan data (update), dan penayangan data (view) pada dasarnya mirip dengan Singly Linked List, namun Doubly Linked List jauh lebih mudah dalam melakukan akses elemen karena iterasi penelusurannya bisa dilakukan maju maupun mundur



# GUIDED 1
### list.h: 

```cpp
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

struct makanan
{
    string nama;
    string jenis;
    float harga;
    float rating;
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node
{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist
{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

// Parameter diperbaiki dengan penambahan simbol & (pass by reference)
void updateFirst(linkedlist &List);
void updateLast(linkedlist &List);
void updateAfter(linkedlist &List, address prev);
void updateBefore(linkedlist &List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
``` 

### list.cpp
```cpp
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(linkedlist &List)
{
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis;
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating = rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodePrev != Nil)
        {
            if (nodePrev == List.last)
            {
                insertLast(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodeNext != Nil)
        {
            if (nodeNext == List.first)
            {
                insertFirst(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl;
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore();
        cout << "Data Berhasil Diupdate!" << endl
             << endl;
    }
}

void updateLast(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore();
        cout << "Data Berhasil Diupdate!" << endl
             << endl;
    }
}

void updateAfter(linkedlist &List, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore();
            cout << "Data Berhasil Diupdate!" << endl
                 << endl;
        }
        else
        {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist &List, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodeNext != Nil && nodeNext->prev != Nil)
        {
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore();
            cout << "Data Berhasil Diupdate!" << endl
                 << endl;
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void findByName(linkedlist List, string nama)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.nama == nama)
        {
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.jenis == jenis)
        {
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.rating >= minRating)
        {
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

void deleteFirst(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if (List.first == List.last)
    {
        List.first = List.last = Nil;
    }
    else
    {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if (List.first == List.last)
    {
        List.first = List.last = Nil;
    }
    else
    {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (Prev == Nil || Prev->next == Nil)
    {
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if (Prev->next == List.last)
    {
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (nodeNext == Nil || nodeNext->prev == Nil)
    {
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if (nodeNext->prev == List.first)
    {
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target)
{
    if (isEmpty(List) == true || target == Nil)
    {
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if (target == List.first)
    {
        deleteFirst(List);
    }
    else if (target == List.last)
    {
        deleteLast(List);
    }
    else
    {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama)
{
    if (isEmpty(List))
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address target = List.first;
    while (target != Nil && target->isidata.nama != nama)
    {
        target = target->next;
    }
    if (target == Nil)
    {
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }
    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

### main.cpp:
```cpp
#include "listMakanan.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    // D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);
    cout << endl;

    findByName(List, "Nasgor");
    findByMinRating(List, 9.0);
    cout << endl;

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl
         << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```
### Penjelasan: Program C++ ini mengimplementasikan struktur data Doubly Linked List secara modular untuk mengelola daftar menu makanan yang memuat informasi nama, jenis, harga, dan rating. Melalui konsep Doubly Linked List, setiap elemen data saling terhubung dua arah menggunakan pointer next dan prev, sehingga penelusuran serta manipulasi data dapat dilakukan dengan fleksibel baik dari depan maupun belakang. Seluruh kode terbagi menjadi tiga bagian utama: file listMakanan.h sebagai tempat rancangan struktur data dan rancangan fungsi, file listMakanan.cpp yang berisi logika utama operasi seperti penambahan (insert), pengubahan (update data lewat terminal), pencarian (searching berdasarkan nama, jenis, atau rating minimal), dan penghapusan (delete node), serta file main.cpp yang berfungsi menjalankan alur program secara berurutan mulai dari menginput sampel makanan (seperti Mie Ayam, Risol Mayo, dll.), memperbarui data, hingga menghapus elemen dan membebaskan alokasi memorinya.



# Unguided
### 1. Doublylist.h
```cpp
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
#include <string>
using namespace std;

#define Nil NULL

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteNode(List &L, string nopol);

#endif
```

### penjelasan 
[File .h berfungsi sebagai cetak biru (blueprint) yang mendefinisikan rancangan struktur data, tipe data bentukan, konstanta, serta prototipe fungsi tanpa memuat logika cara kerjanya. Berkas ini bertindak seperti daftar menu yang memberi tahu compiler fungsi apa saja yang tersedia, sekaligus memanfaatkan include guard (#ifndef, #define, #endif) untuk mencegah terjadinya bentrok deklarasi ganda saat diakses oleh berkas lain.]




### 2. Singlylist.cpp

```cpp
#include "Doublylist.h"

void CreateList(List &L)
{
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x)
{
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P)
{
    delete P;
    P = Nil;
}

void printInfo(List L)
{
    address P = L.First;
    while (P != Nil)
    {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

void insertFirst(List &L, address P)
{
    if (L.First == Nil)
    {
        L.First = P;
        L.Last = P;
    }
    else
    {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void insertLast(List &L, address P)
{
    if (L.First == Nil)
    {
        L.First = P;
        L.Last = P;
    }
    else
    {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List L, string nopol)
{
    address P = L.First;
    while (P != Nil)
    {
        if (P->info.nopol == nopol)
        {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P)
{
    P = L.First;
    if (L.First == L.Last)
    {
        L.First = Nil;
        L.Last = Nil;
    }
    else
    {
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P)
{
    P = L.Last;
    if (L.First == L.Last)
    {
        L.First = Nil;
        L.Last = Nil;
    }
    else
    {
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P)
{
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != Nil)
    {
        P->next->prev = Prec;
    }
    else
    {
        L.Last = Prec;
    }
    P->next = Nil;
    P->prev = Nil;
}

void deleteNode(List &L, string nopol)
{
    address P = findElm(L, nopol);
    if (P != Nil)
    {
        if (P == L.First)
        {
            deleteFirst(L, P);
        }
        else if (P == L.Last)
        {
            deleteLast(L, P);
        }
        else
        {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P);
    }
}
```


### penjelasan
[File .cpp berisi logika algoritma utama yang merealisasikan seluruh prototipe fungsi dari berkas .h. Di sinilah seluruh proses teknis terjadi, seperti alokasi dan dealokasi memori dinamis (new dan delete), pengaturan rantai pointer (next dan prev), serta kondisi logika yang memanipulasi data di dalam memori secara langsung.]


### 3. Singlylist main.cpp

```cpp
#include "Doublylist.h"

int main()
{
    List L;
    CreateList(L);
    infotype x;

    for (int i = 0; i < 4; i++)
    {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        // Mengecek duplikasi data
        if (findElm(L, x.nopol) != Nil)
        {
            cout << "nomor polisi sudah terdaftar\n";
        }
        else
        {
            address P = alokasi(x);
            insertFirst(L, P); 
        }
        cout << endl;
    }

    cout << "DATA LIST 1\n";
    printInfo(L);
    cout << endl;

    string cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari;
    address found = findElm(L, cari);
    if (found != Nil)
    {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    }
    cout << endl;

    string hapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapus;
    deleteNode(L, hapus);
    cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus.\n\n";

    cout << "DATA LIST 1\n";
    printInfo(L);

    return 0;
}
```
### Output :
![Screenshot Output Unguided 1](output/SinglyList.png)


### penjelasan
[File main.cpp berperan sebagai pusat kendali utama yang mengeksekusi program dan berinteraksi langsung dengan pengguna melalui terminal (cin dan cout). Berkas ini bertugas mengendalikan alur aplikasi secara berurutan, mulai dari membuat list baru, menerima input dari pengguna, memanggil fungsi-fungsi pengolah data dari .cpp, hingga menampilkan hasil akhirnya ke layar.]


## PENJELASAN PROGRAM
[Program di atas dirancang dalam tiga berkas terpisah (modular programming) untuk mengelola pendaftaran kendaraan. Berkas Doublylist.h bertugas sebagai kerangka sistem yang mendefinisikan tipe data kendaraan (plat nomor, warna, tahun) beserta struktur penunjuk maju-mundur (next dan prev), sekaligus mendeklarasikan daftar nama fungsinya. Berkas Doublylist.cpp memuat implementasi atau "otak" dari fungsi-fungsi tersebut, mencakup mekanisme penyisipan data dari depan (insertFirst) agar data terbaru muncul paling atas saat dicetak, fitur pengecekan duplikasi agar plat nomor yang sama tidak masuk ke list (findElm), serta logika penghapusan data secara presisi dengan memutus dan menyambungkan kembali kedua kaitan penunjuknya. Terakhir, berkas main.cpp adalah program eksekusi yang langsung berinteraksi dengan user melalui terminal, tempat di mana sistem menerima input registrasi kendaraan secara berulang, menolak registrasi plat ganda, menanyakan data yang ingin dicari, dan mengeksekusi penghapusan plat tertentu sesuai permintaan.]

# Kesimpulan
[Kesimpulan dari praktikum modul ini adalah implementasi struktur data Doubly Linked List secara signifikan meningkatkan fleksibilitas dan efisiensi dalam manipulasi data karena program tidak hanya bisa melangkah maju, tetapi juga mundur menelusuri memori menggunakan penunjuk ganda. Pemecahan arsitektur Abstract Data Type (ADT) ke dalam format modular memudahkan programmer membangun fitur-fitur kompleks—seperti pencarian data spesifik dan validasi anti-duplikasi (find element)—yang menjadi fondasi esensial untuk mengelola basis data dinamis pada kehidupan nyata.]


### Referensi
#### Modul pembelajaran


