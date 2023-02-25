#include "RekeningTabungan.h"
#include "Rekening.h"

// Konstruktor menginisialisi saldo (parameter 1) dan biaya transaksi (parameter 2)
// Set biaya transaksi 0.0 apabila biaya transaksi bernilai negatif
RekeningTabungan::RekeningTabungan(double sl, double bt) : Rekening(sl) { biayaTransaksi = bt < 0 ? 0 : bt; }
// Getter, Setter
void RekeningTabungan::setBiayaTransaksi(double bt) { biayaTransaksi = bt; }
double RekeningTabungan::getBiayaTransaksi() const { return biayaTransaksi; }
// Member Function
// Panggil fungsi simpanUang dari parent class
// Kurangkan saldo dengan biaya transaksi
void RekeningTabungan::simpanUang(double jml)
{
    this->Rekening::simpanUang(jml - biayaTransaksi);
    // this->setSaldo(this->getSaldo() - biayaTransaksi);
}
// Panggil fungsi tarikUang dari parent class
// Kurangkan saldo dengan biaya transaksi hanya jika penarikan uang berhasil
// Saldo mungkin saja menjadi negatif apabila setelah penarikan, saldo < biaya transaksi
// Kembalikan boolean yang mengindikasikan apakah uang berhasil ditarik atau tidak
bool RekeningTabungan::tarikUang(double jml)
{
    bool berhasil = this->Rekening::tarikUang(jml);
    if (berhasil)
    {
        this->setSaldo(this->getSaldo() - biayaTransaksi);
    }
    return berhasil;
}
