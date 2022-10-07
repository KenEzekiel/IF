#include <stdio.h>
#include "prioqueuetime.h"

int main()
{
    int i, n;
    int runtime = 0;
    int timenow = 0;
    infotype x, val;
    PrioQueueTime Q;
    scanf("%d", &n);
    MakeEmpty(&Q, n + 1);
    for (i = 0; i < n; i++)
    {
        timenow = i;
        scanf("%d %c", &Time(x), &Info(x));
        Enqueue(&Q, x);
        // PrintPrioQueueTime(Q);
        if (timenow >= runtime)
        {
            Dequeue(&Q, &val);
            printf("%d %c\n", runtime, Info(val));
            runtime += Time(val);
        }
    }

    while (!IsEmpty(Q))
    {
        Dequeue(&Q, &val);
        printf("%d %c\n", runtime, Info(val));
        runtime += Time(val);
    }
    return 0;
}