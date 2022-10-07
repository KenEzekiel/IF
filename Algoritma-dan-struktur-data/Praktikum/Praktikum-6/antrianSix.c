#include <stdio.h>
#include "queue.h"

int main()
{
    boolean loop = true;
    int input1, input2 = 0;
    int val, minmax;
    int waktuMin;
    int waktuMax;
    int countDilayani;
    float sumDilayani = 0;
    int i;
    float mean;
    Queue antrian;
    Queue antrianDilayani;
    CreateQueue(&antrianDilayani);
    CreateQueue(&antrian);

    while (loop)
    {
        val = 0;
        scanf("%d", &input1);
        // displayQueue(antrian);

        if (input1 == 2)
        {
            // displayQueue(antrian);
            if (isEmpty(antrian))
            {
                printf("Queue kosong\n");
            }
            else
            {
                dequeue(&antrian, &val);
                // printf("%d\n", val);
                sumDilayani += (float)val;
                enqueue(&antrianDilayani, val);
            }
        }
        if (input1 == 1)
        {
            // displayQueue(antrian);
            scanf("%d", &input2);
            // printf("input : %d\n", input2);
            if (isFull(antrian))
            {
                printf("Queue penuh\n");
            }
            else
            {
                enqueue(&antrian, input2);
            }
        }
        if (input1 == 0)
        {
            // displayQueue(antrian);
            loop = false;
            // printf("%d\n", countDilayani);
            if (length(antrianDilayani) == 0)
            {
                printf("0\n");
                printf("Tidak bisa dihitung\n");
                printf("Tidak bisa dihitung\n");
                printf("Tidak bisa dihitung\n");
            }
            else
            {
                countDilayani = (float)length(antrianDilayani);
                printf("%d\n", countDilayani);
                mean = sumDilayani / countDilayani;
                dequeue(&antrianDilayani, &minmax);
                waktuMin = minmax;
                waktuMax = minmax;
                for (i = 1; i < countDilayani; i++)
                {
                    dequeue(&antrianDilayani, &minmax);
                    if (minmax < waktuMin)
                    {
                        waktuMin = minmax;
                    }
                    if (minmax > waktuMax)
                    {
                        waktuMax = minmax;
                    }
                }
                printf("%d\n", waktuMin);
                printf("%d\n", waktuMax);
                printf("%.2f\n", mean);
            }
        }
    }
    return 0;
}