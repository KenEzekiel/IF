#include "liststatik.h"
#include <stdio.h>

int main()
{
    int X, min, max, med;
    int i;
    int count = 0;
    int idx = IDX_UNDEF;
    ListStatik L;
    boolean valid = false;

    readList(&L);

    printList(L);
    printf("\n");

    scanf("%d", &X);

    for (i = 0; i <= listLength(L) - 1; i++)
    {
        if (ELMT(L, i) == X)
        {
            count++;
            idx = i;
        }
    }

    printf("%d\n", count);

    if (idx != IDX_UNDEF)
    {
        printf("%d\n", idx);
    }
    else
    {
        printf("%d tidak ada\n", X);
    }

    extremeValues(L, &max, &min);

    sortList(&L, true);
    if ((listLength(L) % 2) == 0)
    {
        med = ELMT(L, (listLength(L) / 2) - 1);
    }
    else
    {
        med = ELMT(L, (((listLength(L)) + 1) / 2) - 1);
    }

    if (X == max)
    {
        printf("maksimum\n");
    }

    if (X == min)
    {
        printf("minimum\n");
    }

    if (X == med)
    {
        printf("median\n");
    }

    return 0;
}