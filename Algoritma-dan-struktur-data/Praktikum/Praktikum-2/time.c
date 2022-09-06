#include <stdio.h>
#include "time.h"
#include "boolean.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid(int H, int M, int S)
{
    /* Mengirim true jika H,M,S dapat membentuk T yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    if (((H >= 0) && (H <= 23)) && ((M >= 0) && (M <= 59)) && ((S >= 0) && (S <= 59)))
    {
        return true;
    }
    else
        return false;
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime(TIME *T, int HH, int MM, int SS)
{
    /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
    /* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
    if (IsTIMEValid(HH, MM, SS) == true)
    {
        Hour(*T) = HH;
        Minute(*T) = MM;
        Second(*T) = SS;
    }
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME(TIME *T)
{
    /* I.S. : T tidak terdefinisi */
    /* F.S. : T terdefinisi dan merupakan jam yang valid */
    /* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
    /* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
    /* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
       dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
    /* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
       diulangi hingga didapatkan jam yang valid. */
    /* Contoh:
       60 3 4
       Jam tidak valid
       1 3 4
       --> akan terbentuk TIME <1,3,4> */

    int HH, MM, SS;
    boolean valid = false;

    while (valid != true)
    {
        scanf("%d %d %d", &HH, &MM, &SS);

        if (IsTIMEValid(HH, MM, SS) == true)
        {
            CreateTime(T, HH, MM, SS);
            valid = true;
        }
        else
            printf("Jam tidak valid\n");
    }
}

void TulisTIME(TIME T)
{
    /* I.S. : T sembarang */
    /* F.S. : Nilai T ditulis dg format HH:MM:SS */
    /* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
       tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
    int HH, MM, SS;

    HH = Hour(T);
    MM = Minute(T);
    SS = Second(T);

    printf("%02d", HH);
    printf(":");
    printf("%02d", MM);
    printf(":");
    printf("%02d", SS);
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik(TIME T)
{
    /* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
    /* Rumus : detik = 3600*HH + 60*MM + SS */
    /* Nilai maksimum = 3600*23+59*60+59 */
    /*KAMUS LOKAL*/

    long jumlah = Hour(T) * 3600 + Minute(T) * 60 + Second(T);

    return jumlah;
}

TIME DetikToTIME(long N)
{
    /* Mengirim  konversi detik ke TIME */
    /* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
       mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
       N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
    long N1;
    long HH, MM, SS, sisa;
    TIME T;
    boolean loop;

    if (N < 0)
    {
        N1 = (-1) * N;
    }
    else
    {
        N1 = N;
    }

    while (loop == true)
    {
        N1 = N1 % 86400;
        if (N1 < 86400)
        {
            loop = false;
        }
    }

    HH = N1 / 3600;
    sisa = N1 % 3600;
    MM = sisa / 60;
    SS = sisa % 60;

    CreateTime(&T, HH, MM, SS);
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1=T2, false jika tidak */
    if ((Hour(T1) == Hour(T2)) && (Minute(T1) == Minute(T2)) && (Second(T1) == Second(T2)))
    {
        return true;
    }
    else
        return false;
}
boolean TNEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1 tidak sama dengan T2 */
    if ((Hour(T1) != Hour(T2)) || (Minute(T1) != Minute(T2)) || (Second(T1) != Second(T2)))
    {
        return true;
    }
    else
        return false;
}
boolean TLT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1<T2, false jika tidak */
    /*KAMUS LOKAL*/
    long detik1, detik2;

    /*ALGORITMA*/
    detik1 = TIMEToDetik(T1);
    detik2 = TIMEToDetik(T2);

    if (detik1 < detik2)
    {
        return true;
    }
    else
        return false;
}
boolean TGT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1>T2, false jika tidak */
    /*KAMUS LOKAL*/
    long detik1, detik2;

    /*ALGORITMA*/
    detik1 = TIMEToDetik(T1);
    detik2 = TIMEToDetik(T2);

    if (detik1 > detik2)
    {
        return true;
    }
    else
        return false;
}
/* *** Operator aritmatika TIME *** */
TIME NextDetik(TIME T)
{
    /* Mengirim 1 detik setelah T dalam bentuk TIME */
    /*KAMUS LOKAL*/
    long detik;

    /*ALGORITMA*/
    detik = TIMEToDetik(T);
    detik = detik + 1;

    return DetikToTIME(detik);
}
TIME NextNDetik(TIME T, int N)
{
    /* Mengirim N detik setelah T dalam bentuk TIME */
    /*KAMUS LOKAL*/
    long detik;

    /*ALGORITMA*/
    detik = TIMEToDetik(T);
    detik = detik + N;

    return DetikToTIME(detik);
}
TIME PrevDetik(TIME T)
{
    /* Mengirim 1 detik sebelum T dalam bentuk TIME */
    /*KAMUS LOKAL*/
    long detik;

    /*ALGORITMA*/
    detik = TIMEToDetik(T);
    detik = detik - 1;

    return DetikToTIME(detik);
}
TIME PrevNDetik(TIME T, int N)
{
    /* Mengirim N detik sebelum T dalam bentuk TIME */
    /*KAMUS LOKAL*/
    long detik;

    /*ALGORITMA*/
    detik = TIMEToDetik(T);
    detik = detik - N;

    return DetikToTIME(detik);
}
/* *** Kelompok Operator Aritmetika *** */
long Durasi(TIME TAw, TIME TAkh)
{
    /* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
    /* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
    /*KAMUS LOKAL*/
    long detik1, detik2, durasi;

    /*ALGORITMA*/
    detik1 = TIMEToDetik(TAw);
    detik2 = TIMEToDetik(TAkh);

    if (detik1 > detik2)
    {
        durasi = detik1 - detik2 + 86400;
    }
    else
    {
        durasi = detik2 - detik1;
    }

    return durasi;
}
