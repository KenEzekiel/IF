#include "test.hpp"
#include <iostream>

int main()
{
    Mobil b;
    Mobil a(5);

    // const attribute yang punya default value bisa di overwrite, but is it best practice?

    a.printInfo();
    b.printInfo();

    int c = a.getKap();
    std::cout << c << std::endl;

    return 0;
}