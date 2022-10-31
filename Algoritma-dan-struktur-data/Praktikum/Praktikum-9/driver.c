#include "list_circular.h"
#include <stdio.h>

int main()
{
    List L, M;
    ElType val;

    CreateList(&L);

    printf("List kosong? %d\n", isEmpty(L));
    insertFirst(&L, 1);
    insertLast(&L, 3);
    insertFirst(&L, 2);
    displayList(L);

    // printf("panjang list : %d\n", length(L));
    // deleteAt(&L, 1, &val);
    // printf("val : %d\n", val);
    // displayList(L);
    deleteLast(&L, &val);
    printf("val : %d\n", val);
    displayList(L);
    deleteFirst(&L, &val);
    printf("val : %d\n", val);
    displayList(L);

    insertFirst(&L, 1);
    insertLast(&L, 3);
    // insertAt(&L, 2, 1);
    displayList(L);

    CreateList(&M);
    insertFirst(&M, 4);
    insertLast(&M, 6);
    // insertAt(&M, 5, 1);
    displayList(M);

    // Address p;

    // List N = concat(L, M);
    // displayList(N);
    // displayList(L);
    // displayList(M);
    // val = getElmt(N, 2);
    // printf("idx 2 di N: %d\n", val);
    // setElmt(&N, 1, 10);
    // displayList(N);
    // printf("Apakah 6 ada di list? %d\n", addrSearch(l, p));

    return 0;
}