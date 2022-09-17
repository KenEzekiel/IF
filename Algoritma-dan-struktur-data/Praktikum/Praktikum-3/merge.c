#include "listdin.h"
#include <stdio.h>

int main()
{
    ListDin L1, L2, L3;
    int i;
    CreateListDin(&L1, 200);
    CreateListDin(&L2, 200);
    CreateListDin(&L3, 400);

    readList(&L1);
    readList(&L2);

    for (i = 0; i < NEFF(L1); i++)
    {
        if (indexOf(L2, ELMT(L1, i)) == IDX_UNDEF)
        {
            insertLast(&L3, ELMT(L1, i));
        }
    }

    for (i = 0; i < NEFF(L2); i++)
    {
        insertLast(&L3, ELMT(L2, i));
    }

    sort(&L3, true);

    printf("%d\n", NEFF(L3));
    printList(L3);
    printf("\n");

    return 0;
}