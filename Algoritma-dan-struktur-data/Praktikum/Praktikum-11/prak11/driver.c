#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    List l;
    l = konso(l, 1);
    printf("1");
    l = konsb(l, 2);
    printf("2");
    int max = maxList(l);
    printf("3");
    int min = minList(l);
    printf("4");
    int sum = sumList(l);
    printf("5");
    float avg = averageList(l);
    printf("6");
    List inv = inverseList(l);
    printf("max %d min %d sum %d avg %f\n", max, min, sum, avg);
    displayList(inv);
}