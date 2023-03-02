#include "RestoranRamen.hpp"
#include <map>
#include <iostream>
using namespace std;

// Menambah jumlah order yang dipesan oleh meja n, dengan harga p
// Jika meja sudah diisi maka akan menambah total yang telah dipesan
void RestoranRamen::tambahOrder(int n, int p)
{
    map<int, int>::iterator itr = this->daftarMeja.find(n);
    if (itr != this->daftarMeja.end())
    {
        // found n
        this->daftarMeja[n] += p;
    }
    else
    {
        this->daftarMeja.insert(pair<int, int>(n, p));
    }
}

// Mengembalikan total harga pesanan pada meja n, menghapus entri untuk meja tersebut
int RestoranRamen::tutupOrder(int n)
{
    int p = this->daftarMeja[n];
    this->daftarMeja.erase(n);
    return p;
}

// Mengembalikan total harga pesanan pada meja n
int RestoranRamen::cekTotal(int n)
{
    return this->daftarMeja[n];
}

// Mengembalikan jumlah meja yang terisi saat itu
// Restoran mungkin kosong
int RestoranRamen::totalMeja()
{
    return this->daftarMeja.size();
}

// Mencetak semua meja yang terisi pada restoran diakhiri dengan new line
// Contoh :
/*
    Meja 1 = 5000
    Meja 2 = 3000
    Meja 4 = 10000
*/
// Jika restoran kosong akan mencetak "Restoran kosong" diakhiri new line
void RestoranRamen::cetakMeja()
{

    if (this->daftarMeja.size() == 0)
    {
        cout << "Restoran kosong" << endl;
    }
    else
    {
        map<int, int>::iterator itr = this->daftarMeja.begin();

        while (itr != this->daftarMeja.end())
        {
            cout << "Meja " << itr->first << " = " << itr->second << endl;
            itr++;
        }
    }
}

// map<int, int> daftarMeja;
