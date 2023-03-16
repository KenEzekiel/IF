// Kelas Pecahan
// File: Pecahan.cpp
#include "Pecahan.hpp"

#include <iostream>

using namespace std;

// int n; // pembilang, n >= 0
// int d; // penyebut, d > 0

// ctor: set n = 0 dan d = 1
pecahan::pecahan()
{
    this->n = 0;
    this->d = 1;
}

// ctor: set n = _n dan d = _d
pecahan::pecahan(int _n, int _d)
{
    this->n = _n;
    this->d = _d;
}

pecahan::pecahan(const pecahan &P)
{
    this->n = P.n;
    this->d = P.d;
} // cctor:

pecahan::~pecahan()
{

} // dtor

int pecahan::getPemb()
{
    return this->n;
} // Menghasillkan pembilang n
int pecahan::getPeny()
{
    return this->d;
} // Menghasilkan penyebut d

void pecahan::setPemb(int _n)
{
    this->n = _n;
} // Mengubah nilai n menjadi _n
void pecahan::setPeny(int _d)
{
    this->d = _d;
} // Mengubah nilai d menjadi _d

pecahan pecahan::operator+(const pecahan &P)
{
    pecahan ret((this->n * P.d + P.n * this->d), this->d * P.d);
    return ret;
}
// Menambahkan pecahan dengan P
// Rumus = n1/d1 + n2/d2 = (n1*d2 + n2*d1)/d1*d2

pecahan pecahan::operator-(const pecahan &P)
{
    pecahan ret((this->n * P.d - P.n * this->d), this->d * P.d);
    return ret;
}
// Menambahkan pecahan dengan P
// Rumus = n1/d1 - n2/d2 = (n1*d2 - n2*d1)/d1*d2

// Kok perkaliannya d nya juga di kali?
pecahan pecahan::operator*(int x)
{

    if (x > 0)
    {
        pecahan ret(this->n * x, this->d * x);
        return ret;
    }
    else
    {
        return *this;
    }
}
// Mengalikan pembilang P dengan x dan penyebut P dengan x
// Syarat: x > 0
// Rumus = n1/d1 = (n1*x)/(d1*x)

bool pecahan::operator==(const pecahan &P)
{
    if (this->n * P.d == P.n * this->d)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Mengecek apakah kedua pecahan memiliki nilai yang sama
// Hint: bandingkan dengan gcd, tidak boleh dibandingkan dengan RealP()!

float pecahan::RealP()
{
    float ret = (float)this->n / (float)this->d;
    return ret;
}
// Menghasilkan bentuk desimal dari pecahan

void pecahan::Print()
{
    cout << this->n << "/" << this->d;
}
// Mencetak pecahan dalam format: n/d (tanpa tambahan karakter apa pun
// di depan, tengah, atau belakang)
