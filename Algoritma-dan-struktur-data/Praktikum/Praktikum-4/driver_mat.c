#include "matrix.h"
#include <stdio.h>

int main()
{
    Matrix m1;
    int i, j;
    readMatrix(&m1, 3, 3);
    displayMatrix(m1);
    float d = determinant(m1);
    printf("%f", d);

    return 0;
}