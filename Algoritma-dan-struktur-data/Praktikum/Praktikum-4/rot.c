#include "matrix.c"
#include <stdio.h>

int main()
{

    Matrix m;

    readMatrix(&m, 4, 4);

    printf("Matrix yang sudah dirotasi: \n");
    RotateMat(&m);

    displayMatrix(m);
    return 0;
}