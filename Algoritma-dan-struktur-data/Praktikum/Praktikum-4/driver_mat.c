#include "matrix.h"
#include <stdio.h>

int main()
{
    Matrix m1;
    readMatrix(&m1, 2, 2);
    displayMatrix(m1);
    printf("%f", determinant(m1));

    return 0;
}