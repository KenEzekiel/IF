/*
Kenneth Ezekiel Suprantoni
13521089
Implementasi point.h
*/

#include <stdio.h>
#include "point.h"
#include <math.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint(POINT *P, float X, float Y)
{
    /* Membentuk sebuah POINT dari komponen-komponennya */
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT(POINT *P)
{
    /* Membaca nilai absis dan ordinat dari keyboard dan membentuk
       POINT P berdasarkan dari nilai absis dan ordinat tersebut */
    /* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
    /* Contoh: 1 2
       akan membentuk POINT <1,2> */
    /* I.S. Sembarang */
    /* F.S. P terdefinisi */
    float X, Y;

    scanf("%f %f", &X, &Y);

    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void TulisPOINT(POINT P)
{
    /* Nilai P ditulis ke layar dengan format "(X,Y)"
       tanpa spasi, enter, atau karakter lain di depan, belakang,
       atau di antaranya
       Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    /* I.S. P terdefinisi */
    /* F.S. P tertulis di layar dengan format "(X,Y)" */

    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ(POINT P1, POINT P2)
{
    /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

    if ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)))
    {
        return true;
    }
    else
        return false;
}

boolean NEQ(POINT P1, POINT P2)
{
    /* Mengirimkan true jika P1 tidak sama dengan P2 */

    if ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)))
    {
        return true;
    }
    else
        return false;
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin(POINT P)
{
    /* Menghasilkan true jika P adalah titik origin */

    if ((Absis(P) == 0) && (Ordinat(P) == 0))
    {
        return true;
    }
    else
        return false;
}
boolean IsOnSbX(POINT P)
{
    /* Menghasilkan true jika P terletak Pada sumbu X */

    if (Ordinat(P) == 0)
    {
        return true;
    }
    else
        return false;
}
boolean IsOnSbY(POINT P)
{
    /* Menghasilkan true jika P terletak pada sumbu Y */

    if (Absis(P) == 0)
    {
        return true;
    }
    else
        return false;
}
int Kuadran(POINT P)
{
    /* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
    /* Prekondisi : P bukan titik origin, */
    /*              dan P tidak terletak di salah satu sumbu */

    /* KAMUS LOKAL */
    boolean XPositive, YPositive;
    /* 1: X+ Y+, 2: X- Y+, 3: X- Y-, 4: X+ Y-*/

    /* ALGORITMA */

    if (Absis(P) > 0)
    {
        XPositive = true;
    }
    else
        XPositive = false;

    if (Ordinat(P) > 0)
    {
        YPositive = true;
    }
    else
        YPositive = false;

    if (XPositive == true)
    {
        if (YPositive == true)
        {
            return 1;
        }
        else
            return 4;
    }
    else if (YPositive == true)
    {
        return 2;
    }
    else
        return 3;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX(POINT P)
{
    /* Mengirim salinan P dengan absis ditambah satu */
    /*KAMUS LOKAL*/
    POINT PX;
    /*ALGORITMA*/
    Absis(PX) = Absis(P) + 1;
    Ordinat(PX) = Ordinat(P);

    return PX;
}
POINT NextY(POINT P)
{
    /* Mengirim salinan P dengan ordinat ditambah satu */
    /*KAMUS LOKAL*/
    POINT PX;
    /*ALGORITMA*/
    Absis(PX) = Absis(P);
    Ordinat(PX) = Ordinat(P) + 1;

    return PX;
}
POINT PlusDelta(POINT P, float deltaX, float deltaY)
{
    /* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    /*KAMUS LOKAL*/
    POINT PX;
    /*ALGORITMA*/
    Absis(PX) = Absis(P) + deltaX;
    Ordinat(PX) = Ordinat(P) + deltaY;

    return PX;
}
POINT MirrorOf(POINT P, boolean SbX)
{
    /* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
    /* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
    /* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    /*KAMUS LOKAL*/
    POINT PX;
    /*ALGORITMA*/
    if (SbX == true)
    {
        Absis(PX) = Absis(P);
        Ordinat(PX) = (Ordinat(P) * (-1));
    }
    else
    {
        Absis(PX) = (Absis(P) * (-1));
        Ordinat(PX) = Ordinat(P);
    }
    return PX;
}
float Jarak0(POINT P)
{
    /* Menghitung jarak P ke (0,0) */
    /*KAMUS LOKAL*/
    float jarak;

    /*ALGORITMA*/
    jarak = (Absis(P) * Absis(P)) + (Ordinat(P) * Ordinat(P));
    jarak = sqrt(jarak);

    return jarak;
}
float Panjang(POINT P1, POINT P2)
{
    /* Menghitung panjang garis yang dibentuk P1 dan P2 */
    /* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
    /* Tuliskan spec fungsi yang lebih tepat. */
    /*KAMUS LOKAL*/
    float jarak, dx, dy;

    /*ALGORITMA*/
    if (Absis(P1) >= Absis(P2))
    {
        dx = Absis(P1) - Absis(P2);
    }
    else
        dx = Absis(P2) - Absis(P1);

    if (Ordinat(P1) >= Ordinat(P2))
    {
        dy = Ordinat(P1) - Ordinat(P2);
    }
    else
        dy = Ordinat(P2) - Ordinat(P1);

    jarak = (dx * dx) + (dy * dy);
    jarak = sqrt(jarak);

    return jarak;
}
void Geser(POINT *P, float deltaX, float deltaY)
{
    /* I.S. P terdefinisi */
    /* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}
void GeserKeSbX(POINT *P)
{
    /* I.S. P terdefinisi */
    /* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
    /* Proses : P digeser ke sumbu X. */
    /* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */

    Ordinat(*P) = 0;
}
void GeserKeSbY(POINT *P)
{
    /* I.S. P terdefinisi*/
    /* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
    /* Proses : P digeser ke sumbu Y. */
    /* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */

    Absis(*P) = 0;
}
void Mirror(POINT *P, boolean SbX)
{
    /* I.S. P terdefinisi */
    /* F.S. P dicerminkan tergantung nilai SbX atau SbY */
    /* Jika SbX true maka dicerminkan terhadap sumbu X */
    /* Jika SbX false maka dicerminkan terhadap sumbu Y */

    if (SbX == true)
    {
        Ordinat(*P) = Ordinat(*P) * (-1);
    }
    else
        Absis(*P) = Absis(*P) * (-1);
}
void Putar(POINT *P, float Sudut)
{
    /* I.S. P terdefinisi */
    /* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */

    /*KAMUS LOKAL*/
    float sudutDalamRadian, xAksen, yAksen;

    sudutDalamRadian = (-1) * Sudut * (M_PI / 180);
    xAksen = (Absis(*P) * cos(sudutDalamRadian)) - (Ordinat(*P) * sin(sudutDalamRadian));
    yAksen = (Absis(*P) * sin(sudutDalamRadian)) + (Ordinat(*P) * cos(sudutDalamRadian));
    Absis(*P) = xAksen;
    Ordinat(*P) = yAksen;
}