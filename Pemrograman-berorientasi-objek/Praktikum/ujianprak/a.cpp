#include "Pecahan.hpp"
#include <iostream>

using namespace std;

int main()
{
    pecahan a(2, 3);
    pecahan b(a);
    pecahan d = a * 5;

    pecahan e = a + b;

    pecahan f = a - b;

    float flo = a.RealP();

    a.Print();
    cout << endl;
    b.Print();
    cout << endl;
    d.Print();
    cout << endl;
    e.Print();
    cout << endl;
    f.Print();
    cout << endl;

    bool c = a == b;
    cout << c << endl
         << flo << endl
         << d.RealP() << endl
         << e.RealP() << endl
         << f.RealP() << endl;
    return 0;
}