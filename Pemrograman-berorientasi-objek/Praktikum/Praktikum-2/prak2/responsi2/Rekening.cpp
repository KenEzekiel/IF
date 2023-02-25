#include "Rekening.h"

// Konstruktor untuk menginisialisasi saldo
// Set saldo 0.0 apabila saldo bernilai negatif
Rekening::Rekening(double sl) { saldo = sl < 0 ? 0 : sl; }
// Getter, Setter
void Rekening::setSaldo(double sl) { saldo = sl; }
double Rekening::getSaldo() const { return saldo; }
// Member Function
// Tambahkan sejumlah nominal uang ke saldo
void Rekening::simpanUang(double jml) { saldo += jml; }
// Kurangkan sejumlah nominal uang dari saldo apabila saldo mencukupi (tidak negatif setelah dikurangkan)
// Kembalikan boolean yang mengindikasikan apakah uang berhasil ditarik atau tidak
bool Rekening::tarikUang(double jml)
{
    if (saldo - jml >= 0)
    {
        saldo -= jml;
        return true;
    }
    else
    {
        return false;
    }
}
