#include "time.c"

int main()
{
    TIME T1, T2, T3;
    CreateTime(&T1, 5, 30, 20);
    printf("Masukkan HH MM SS dipisahkan 1 spasi: ");
    BacaTIME(&T2);
    printf("\nT1 adalah:\n ");
    TulisTIME(T1);
    printf("\nT2 dalam detik:\n %ld\n", TIMEToDetik(T2));
    long detik = 33600;
    T3 = DetikToTIME(detik);
    printf("T3 jika detik 33600 adalah:\n ");
    TulisTIME(T3);
    printf("\nApakah T1 sama dengan T3?\n %d\n", TEQ(T1, T3));
    printf("Apakah T1 tidak sama dengan T2?\n %d\n", TNEQ(T1, T2));
    printf("Apakah T2 lebih kecil dari T3?\n %d\n", TLT(T2, T3));
    printf("Apakah T1 lebih besar dari T3?\n %d\n", TGT(T1, T3));
    printf("1 Detik setelah T3?\n ");
    TIME T4 = NextDetik(T3);
    TulisTIME(T4);
    printf("\n10 Detik setelah T2?\n ");
    TIME T5 = NextNDetik(T2, 10);
    TulisTIME(T5);
    printf("\n1 Detik sebelum T1?\n ");
    TIME T6 = PrevDetik(T1);
    TulisTIME(T6);
    printf("\n10 Detik sebelum T3?\n ");
    TIME T7 = PrevNDetik(T3, 10);
    TulisTIME(T7);
    printf("\nDurasi antara T1 dan T2 (T1 sbg TAwal) adalah:\n %ld\n", Durasi(T1, T2));
    printf("\nDurasi antara T2 dan T1 (T2 sbg TAwal) adalah:\n %ld\n", Durasi(T2, T1));
}