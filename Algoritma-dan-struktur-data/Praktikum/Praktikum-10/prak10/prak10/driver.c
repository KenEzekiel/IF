#include "queuelinked.h"

#include <stdio.h>

int main()
{
    Queue q;
    CreateQueue(&q);

    printf("is it empty? %d\n", isEmpty(q));
    printf("length? %d\n", length(q));
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    DisplayQueue(q);
    int val;
    dequeue(&q, &val);
    DisplayQueue(q);

    return 0;
}
