#include <stdio.h>
#include "liststatik.c"

int main()
{
    ListStatik L;
    int min, max;
    readList(&L);
    // printf("%d\n", listLength(L));
    printList(L);
    sortList(&L, false);
    printList(L);
    extremeValues(L, &max, &min);
    printf("%d %d", min, max);
    insertFirst(&L, 100);
}