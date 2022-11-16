#include <stdio.h>
#include "listrec.h"

int main()
{
    List L;

    printf("Is list empty? %d\n", isEmpty(L));
    printf("Is list one element? %d\n", isOneElmt(L));
    // printf("Length? %d\n", length(L));

    // L = konso(L, 1);
    // displayList(L);
    // printf("Is list one element? %d\n", isOneElmt(L));
    // printf("Length? %d\n", length(L));
    // L = konsb(L, 2);
    // displayList(L);
    // printf("Is list one element? %d\n", isOneElmt(L));
    // printf("Length? %d\n", length(L));

    // printf("Head? %d\n", head(L));
    // printf("Tail? %d\n", tail(L));

    // List copyan = copy(L);
    // List concatan = concat(L, copyan);
    // printf("Length? %d\n", length(copyan));
    // printf("is 1 member of L? %d\n", isMember(L, 1));

    return 0;
}