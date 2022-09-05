#include "point.c"

int main()
{

    POINT p1, p2;
    float x, y;
    CreatePoint(&p1, 5, 6);
    printf("Point 1: ");
    TulisPOINT(p1);
    printf("\nMasukkan X dan Y:\n");
    BacaPOINT(&p2);
    TulisPOINT(p2);

    printf("\nApakah p1 == p2?\n %d \n", EQ(p1, p2));
    printf("Apakah p1 != p2?\n %d \n", NEQ(p1, p2));
    printf("Apakah p1 di origin?\n %d \n", IsOrigin(p1));
    printf("Apakah p2 berada di sumbu x?\n %d \n", IsOnSbX(p2));
    printf("Apakah p1 berada di sumbu y?\n %d \n", IsOnSbY(p1));
    printf("p1 berada di kuadran?\n %d \n", Kuadran(p1));
    POINT nextxp = NextX(p1);
    POINT nextyp = NextY(p2);
    POINT pditambah = PlusDelta(p1, 5.5, -7.5);
    printf("X setelah p1 adalah?\n ");
    TulisPOINT(nextxp);
    printf("\nY setelah p2 adalah?\n ");
    TulisPOINT(nextyp);
    printf("\nJika p1 ditambah X sebesar 5.5 dan dikurang Y sebesar 7.5?\n ");
    TulisPOINT(pditambah);
    POINT mirrorX = MirrorOf(p1, true);
    POINT mirrorY = MirrorOf(p2, false);
    printf("\nJika p1 di mirror thd sumbu x maka menjadi:\n ");
    TulisPOINT(mirrorX);
    printf("\nJika p2 di mirror thd sumbu y maka menjadi:\n ");
    TulisPOINT(mirrorY);
    printf("\nJarak dari (0,0) ke p1 adalah:\n %f\n", Jarak0(p1));
    printf("Panjang jika ada garis dari p1 ke p2 adalah:\n %f\n", Panjang(p1, p2));
    printf("Kita geser point p1 sejauh (5,5)\n p1:");
    Geser(&p1, 5, 5);
    TulisPOINT(p1);
    printf("\nKita geser point p2 ke sumbu X\n p2:");
    GeserKeSbX(&p2);
    TulisPOINT(p2);
    printf("\nKita geser point p1 ke sumbu Y\n p1:");
    GeserKeSbY(&p1);
    TulisPOINT(p1);
    POINT p3;
    CreatePoint(&p3, 5, -5);
    printf("\nPoint p3:\n ");
    TulisPOINT(p3);
    printf("\nJika di mirror terhadap sumbu x:\n ");
    Mirror(&p3, true);
    TulisPOINT(p3);
    printf("\nLalu di mirror terhadap sumbu y:\n ");
    Mirror(&p3, false);
    TulisPOINT(p3);
    printf("\nLalu diputar 45.5 derajat:\n ");
    Putar(&p3, 45.5);
    TulisPOINT(p3);

    return 0;
}