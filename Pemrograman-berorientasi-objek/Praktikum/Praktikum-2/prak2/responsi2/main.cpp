#include <iostream>
#include "Hewan.h"
using namespace std;

int main()
{
    Hewan *array_hewan[3];
    Hewan a("a");
    Kucing b("b");
    Anjing c("c");
    array_hewan[0] = &a;
    array_hewan[1] = &b;
    array_hewan[2] = &c;

    for (int i = 0; i < 3; i++)
    {
        array_hewan[i]->print(); // Keluaran = "[Makhluk] ini namanya [nama]\n"
    }
    array_hewan[1] = &c;
    array_hewan[1]->print();
    Kucing *d = new KucingAnggora("d", "1");
    Anjing *e = new AnjingBulldog("e", "2");
    ;
    d->print();
    e->print();
    KucingAnggora f("f", "3");
    AnjingBulldog g("g", "4");
    f.print();
    g.print();
    delete e;
    delete d;
    return 0;
}