#include "matrix.c"
#include <stdio.h>

int main()
{
    Matrix m1;
    readMatrix(&m1, 3, 3);
    displayMatrix(m1);
    float d = det(m1, 3);
    printf("%f", d);

    return 0;
}