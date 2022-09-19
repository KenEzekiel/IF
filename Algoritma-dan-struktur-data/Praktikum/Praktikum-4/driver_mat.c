#include "matrix.h"
#include <stdio.h>

int main()
{
    Matrix m1;
    int i, j;
    readMatrix(&m1, 3, 3);
    displayMatrix(m1);
    float d = determinant(m1);
    printf("%f\n", d);

    Matrix m2;
    copyMatrix(m1, &m2);
    displayMatrix(m2);

    Matrix m3 = multiplyMatrix(m1, m2);
    displayMatrix(m3);
    return 0;
}