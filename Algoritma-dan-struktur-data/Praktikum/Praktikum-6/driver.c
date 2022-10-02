#include "queue.h"
#include <stdio.h>

int main()
{
    Queue a;
    int val;
    CreateQueue(&a);

    // enqueue(&a, 2);
    // dequeue(&a, &val);
    // printf("%d\n", val);

    for (int i = 4; i < 103; i++)
    {
        enqueue(&a, i);
    }
    dequeue(&a, &val);
    printf("%d\n", val);
    enqueue(&a, 999);
    displayQueue(a);
}