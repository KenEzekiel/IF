#include "test.hpp"
#include <iostream>

Mobil::Mobil(){};
Mobil::Mobil(int k) : kap(k){};

int Mobil::getKap() const
{
    return kap;
}

void Mobil::printInfo()
{
    std::cout << kap << std::endl;
}