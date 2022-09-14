#include <stdio.h>
#include "listdin.c"

int main()
{
    ListDin L;
    CreateListDin(&L, 20);
    readList(&L);
    // printf("%d\n", listLength(L));
    printList(L);
}