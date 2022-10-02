#include <stdio.h>

int gura(int x, int y)
{
    return ~(~x & ~y);
}

int rushia(void)
{
    return 1 << 31;
}

unsigned int kobokan(unsigned int x, unsigned int n)
{
    return x & ((1 << n) + (~1 + 1));
}

int fauna(int x, int n)
{
    return (x >> (n << 3)) & 0xff;
}

int yamada(int x)
{
    int higherthanlow = x + (~135 + 1);
    int lowerthanhigh = 182 + (~x + 1);

    // check MSB to see negative or not
    higherthanlow = higherthanlow >> 31;
    lowerthanhigh = lowerthanhigh >> 31;

    return (!higherthanlow & !lowerthanhigh);
}

int pekora(int x)
{
    // 24 = 3 kali geser dikali 8 bit (geser per byte)
    x = (x) << 24 | ((x) >> 24) & 0xff | ((x >> 16) & 0xff) << 8 | ((x >> 8) & 0xff) << 16;

    return x;
}

int mumei(int x, int n)
{
    return (x >> n) & ~(((1 << 31) >> n) << 1);
}

int moona(int x)
{
    int count = 32;
    x = x & (~x + 1);

    count = count + (~(!!x) + 1);
    count = count + (~(((!!(x & 0x0000ffff) << 31) >> 31) & 16) + 1);
    count = count + (~(((!!(x & 0x00ff00ff) << 31) >> 31) & 8) + 1);
    count = count + (~(((!!(x & 0x0f0f0f0f) << 31) >> 31) & 4) + 1);
    count = count + (~(((!!(x & 0x33333333) << 31) >> 31) & 2) + 1);
    count = count + (~(!!(x & 0x55555555)) + 1);

    return count;
}

unsigned int ollie(unsigned int a)
{
    int composite;
    // chinese remainder problem where p1 = 2, p2 = 15
    unsigned int remtwo = a & 1;

    // 32(a / 2) + (a mod 32) is congruent with (2a + b) mod 30
    // i = a div 2
    unsigned int i = a >> 1;
    // check if i is > 15, then div by 32
    i = (i & 15) + (i >> 4);
    i = (i & 15) + (i >> 4);
    i = (i & 15) + (i >> 4);
    i = (i & 15) + (i >> 4);
    i = (i & 15) + (i >> 4);
    i = (i & 15) + (i >> 4);
    i = (i & 15) + (i >> 4);

    i = (i + ((i + 1) >> 4)) & 15;

    return remtwo + (i << 1);
}

unsigned coco(unsigned uf)
{
    unsigned exp = (uf & 0x7F800000) >> 23;
    unsigned frac = (uf & 0x7FFFFF);
    unsigned sign = (uf & 0x80000000);
    // exp = exp + 1;
    // exp = exp << 23;

    if (!(exp ^ 0xff))
    // pass if num is NaN or inf
    {
        return uf;
    }
    if (!(exp & 0xff))
    {
        frac = frac << 1;
    }
    else
    {
        exp = exp + 1;
    }

    if (!(exp ^ 0xff) && frac)
    {
        frac = 0;
    }

    exp = exp << 23;

    uf = sign | exp | frac;

    return uf;
}

int main()
{
    int x, y;
    // int a;
    // scanf("%d", &a);

    // scanf("%d %d", &x, &y);

    // int z = gura(x, y);
    // int z = rushia();
    // unsigned int z = kobokan(x, y);
    // int z = fauna(0x12345678, 1);
    // int z = pekora(0x01020304);
    // int z = ollie(64);
    // int z = moona(a);
    // unsigned int z = ollie(a);
    // unsigned z = coco(1103101952);

    // printf("%d", z);

    for (int i = 0; i <= (0xFF); i++)
    {
        printf("%d -> ollie %d\n", i, ollie(i));
    }

    /*
    for (int i = -200; i <= (200); i++)
    {
        printf("%d -> yamada %d\n", i, yamada(i));
    }
    */
    return 0;
}