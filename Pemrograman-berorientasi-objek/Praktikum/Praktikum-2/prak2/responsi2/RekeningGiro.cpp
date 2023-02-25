#include "RekeningGiro.h"
#include "Rekening.h" // include the Account header file

// Konstruktor menginisialisi saldo (parameter 1) dan suku bunga (parameter 2)
// Set suku bunga 0.0 apabila suku bunga bernilai negatif
RekeningGiro::RekeningGiro(double sl, double sb) : Rekening(sl) { sukuBunga = sb < 0 ? 0 : sb; }
// Getter, Setter
void RekeningGiro::setSukuBunga(double sb) { sukuBunga = sb; }
double RekeningGiro::getSukuBunga() const { return sukuBunga; }
// Member Function
// Bunga dihitung dari saldo dikali suku bunga
double RekeningGiro::hitungBunga() { return this->getSaldo() * sukuBunga; }
