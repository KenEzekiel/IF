#include "Calculator.hpp"
#include <iostream>
#include <string>

using namespace std;

int main () {
    Calculator a;

    string exp = "1+2-3";
    int hasil = a.Evaluate(exp);

    cout << hasil << endl;


    return 0;
}