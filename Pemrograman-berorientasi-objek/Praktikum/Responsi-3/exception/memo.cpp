#include "memo.h"
#include "exception.h"
#include <string>

using namespace std;

Memo::Memo()
{
    pesan = "";
    untuk = "";
}

Memo::Memo(string pesan, string untuk)
{
    if (pesan.length() > PESAN_MAX)
    {
        throw PesanKepanjanganException();
    }
    else
    {
        this->pesan = pesan;
        this->untuk = untuk;
    }
}

Memo &Memo::operator=(Memo &obj)
{
    this->pesan = obj.pesan;
    this->untuk = obj.untuk;
    return *this;
}

string Memo::getPesan()
{
    return this->pesan;
}

string Memo::getUntuk()
{
    return this->untuk;
}