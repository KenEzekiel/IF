#include "matrix.h"
#include <stdio.h>

int countNotZero(Matrix m, int startrow, int startcol, int size)
{
    /*KAMUS LOKAL*/
    int i, j;
    int count = 0;

    /*ALGORITMA*/
    for (i = startrow; i < startrow + size; i++)
    {
        for (j = startcol; j < startcol + size; j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int noOfSub;
    int subWithMostNonzero = 1;
    int mostNonzero = 0;
    int N, M;
    Matrix main;
    int x, i, j;

    scanf("%d", &N);
    scanf("%d", &M);

    createMatrix(N, N, &main);
    readMatrix(&main, N, N);

    noOfSub = (N - M + 1) * (N - M + 1);

    i = 0;
    j = 0;
    for (x = 0; x < noOfSub; x++)
    {
        if (countNotZero(main, i, j, M) > mostNonzero)
        {
            mostNonzero = countNotZero(main, i, j, M);
            // printf("most non zero: %d\n", mostNonzero);
            subWithMostNonzero = x + 1;
        }
        else if (countNotZero(main, i, j, M) == mostNonzero)
        {
        }
        if (j < N - M)
        {
            j++;
        }
        else if ((j == N - M) && (i < N - M))
        {
            i++;
            j = 0;
        }
    }

    printf("%d\n", subWithMostNonzero);
}
