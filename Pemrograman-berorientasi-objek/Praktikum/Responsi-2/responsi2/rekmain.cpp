#include "Rekening.h"
#include "RekeningGiro.h"
#include "RekeningTabungan.h"
#include <iostream>

int main()
{
    Rekening a(10);
    RekeningGiro b(5, 2);
    RekeningTabungan c(6, 2);

    bool f = a.tarikUang(11);
    bool t = a.tarikUang(9);

    double bunga = b.hitungBunga();

    bool g = c.tarikUang(1);
    double l = c.getSaldo();
    bool h = c.tarikUang(3);

    std::cout << f << std::endl
              << t << std::endl
              << bunga << std::endl
              << g << std::endl
              << l << std::endl
              << h << std::endl
              << c.getSaldo() << std::endl
              << std::endl;

    return 0;
}
