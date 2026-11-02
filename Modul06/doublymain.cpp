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