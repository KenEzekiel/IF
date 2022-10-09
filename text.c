#include <stdio.h>

int main()
{
    int tx, ty;
    unsigned ux, uy;
    ux = 0xff000000;
    ty = 0xff000000;

    tx = (int)ux;
    uy = (unsigned)ty;

    printf("%d %u\n", tx, uy);
    printf("%x %x\n", tx, uy);
}