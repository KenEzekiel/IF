#include "Asset.hpp"
#include "BaseAsset.hpp"
#include "AppreciatingAsset.hpp"
#include <cmath>
#include <iostream>

double powerA(double a, int d)
{
    double ret = 1;
    for (int i = 0; i < d; i++)
    {
        ret = ret * a;
    }
    return ret;
}

double AppreciatingAsset::getValue(int years)
{
    double P = this->x->getValue(years);
    double r = (1 + (this->rate));
    long double A = P * powerA(r, years);
    this->x = new BaseAsset(A);
    return A;
}