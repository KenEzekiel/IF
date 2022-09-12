#include <stdio.h>
#include "liststatik.c"

int main()
{
    ListStatik L;
    readList(&L);
    // printf("%d\n", listLength(L));
    printList(L);
    sortList(&L, false);
    printList(L);
}