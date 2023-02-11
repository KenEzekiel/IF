#include "Polinom.hpp"
#include <iostream>

int main()
{
    // issue 1 : kalo a ga di inisialisasi derajatnya, jadi = harus set derajatnya jg
    // issue 2 : return by ref nya gmn
    Polinom a;

    Polinom b(2);

    b.input();

    a = b;

    std::cout << a.getKoefAt(2) << " " << a.getDerajat() << " " << a.substitute(2) << std::endl;

    b.setDerajat(10);
    b.setKoefAt(10, 100);

    a.print();
    b.print();
    b.printKoef();

    return 0;
}