#include "Polinom.hpp"
#include <iostream>
#include <cmath>

Polinom::Polinom()
{
    koef = new int[0];
    derajat = 0;
}

Polinom::Polinom(int x)
{
    koef = new int[x];
    derajat = x;
}

Polinom::Polinom(const Polinom &other)
{
    derajat = other.derajat;
    koef = new int[derajat];
    for (int i = 0; i <= derajat; i++)
    {
        koef[i] = other.koef[i];
    }
}

Polinom::~Polinom()
{
    delete[] koef;
}

Polinom &Polinom::operator=(const Polinom &other)
{
    delete[] koef;
    derajat = other.derajat;
    koef = new int[other.derajat];
    for (int i = 0; i <= other.derajat; i++)
    {
        koef[i] = other.koef[i];
    }

    return *this;
}

int Polinom::getKoefAt(int idx) const
{
    return koef[idx];
}

int Polinom::getDerajat() const
{
    return derajat;
}

void Polinom::setKoefAt(int idx, int val)
{
    if (idx <= derajat)
    {
        koef[idx] = val;
    }
}

void Polinom::setDerajat(int d)
{

    int *temp = new int[derajat];
    for (int i = 0; i <= derajat; i++)
    {
        temp[i] = koef[i];
    }
    delete[] koef;
    koef = new int[d];
    for (int i = 0; i <= d; i++)
    {
        if (i <= derajat)
        {
            koef[i] = temp[i];
        }
        else
        {
            koef[i] = 0;
        }
    }
    derajat = d;
}

void Polinom::input()
{
    for (int i = 0; i <= derajat; i++)
    {
        std::cin >> koef[i];
    }
}

void Polinom::printKoef()
{
    for (int i = 0; i <= derajat; i++)
    {
        std::cout << koef[i] << std::endl;
    }
}

int Polinom::substitute(int x)
{
    int temp = 0;
    for (int i = 0; i <= derajat; i++)
    {
        temp += koef[i] * std::pow(x, i);
    }
    return temp;
}

void Polinom::print()
{
    if (this->substitute(1) == 0)
    {
        std::cout << "0";
    }
    else
    {
        for (int i = 0; i <= derajat; i++)
        {
            if (i == 0)
            {
                if (koef[i] != 0)
                {
                    std::cout << koef[i];
                }
            }
            else
            {
                if (koef[i] != 0)
                {
                    if (koef[i] < 0)
                    {
                        std::cout << koef[i] << "x^" << i;
                    }
                    else
                    {
                        std::cout << "+" << koef[i] << "x^" << i;
                    }
                }
            }
        }
    }
    std::cout << std::endl;
}