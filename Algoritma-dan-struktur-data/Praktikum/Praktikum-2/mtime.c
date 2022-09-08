#include "time.h"
#include <stdio.h>

int main()
{
    int repeat;
    TIME terawal;
    TIME terakhir;
    int i = 0;

    CreateTime(&terawal, 23, 59, 59);
    CreateTime(&terakhir, 0, 0, 0);

    scanf("%d", &repeat);

    for (i; i < repeat; i += 1)
    {
        printf("[%d]\n", i + 1);
        boolean valid = false;
        TIME T1, T2;
        int durasi;
        BacaTIME(&T1);
        BacaTIME(&T2);

        if (TLT(T1, T2) == true)
        {
            durasi = Durasi(T1, T2);
            if (TLT(T1, terawal) == true)
            {
                terawal = T1;
            }
            if (TGT(T2, terakhir) == true)
            {
                terakhir = T2;
            }
        }
        else
        {
            durasi = Durasi(T2, T1);
            if (TLT(T2, terawal) == true)
            {
                terawal = T2;
            }
            if (TGT(T1, terakhir) == true)
            {
                terakhir = T1;
            }
        }
        printf("%d\n", durasi);
    }

    TulisTIME(terawal);
    printf("\n");
    TulisTIME(terakhir);
    printf("\n");
    return 0;
}