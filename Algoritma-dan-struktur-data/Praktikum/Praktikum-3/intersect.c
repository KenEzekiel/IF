#include "liststatik.h"
#include <stdio.h>

int main()
{
    ListStatik L1, L2, L3;
    int len1, len2, i;
    int idxFound;
    int count = 0;

    readList(&L1);
    readList(&L2);
    len1 = listLength(L1);
    len2 = listLength(L2);
    CreateListStatik(&L3);

    for (i = 0; i < len1; i++)
    {
        idxFound = indexOf(L2, ELMT(L1, i));
        if (idxFound != IDX_UNDEF)
        {
            insertLast(&L3, ELMT(L2, idxFound));
            count++;
        }
    }

    sortList(&L3, true);
    printf("%d\n", count);
    printList(L3);
    printf("\n");

    return 0;
}