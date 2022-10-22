// File : bigint.c
// Nama : Kenneth Ezekiel S
// NIM : 13521089

#include <stdio.h>
#include "stack.h"

Stack reverse(Stack S)
{
    Stack temp = S;
    Stack ret;
    int x;

    CreateEmpty(&ret);
    while (!IsEmpty(temp))
    {
        Pop(&temp, &x);
        Push(&ret, x);
    }
    return ret;
}

boolean isSmaller(Stack S1, Stack S2)
{

    Stack ret1, ret2;
    int x, x1, x2;
    int len1 = Top(S1) + 1;
    int len2 = Top(S2) + 1;
    int i;

    if (len1 < len2)
    {
        return true;
    }
    if (len2 < len1)
    {
        return false;
    }

    ret1 = reverse(S1);
    ret2 = reverse(S2);

    for (i = 0; i < len1; i++)
    {
        Pop(&ret1, &x1);
        Pop(&ret2, &x2);
        if (x1 < x2)
        {
            return true;
        }
        else if (x1 > x2)
        {
            return false;
        }
    }
}

int main()
{
    char s1[100];
    char s2[100];
    int i;
    char *s;
    Stack Stack1, Stack2, Stack3, temp;

    CreateEmpty(&Stack1);
    CreateEmpty(&Stack2);
    CreateEmpty(&Stack3);

    scanf("%s", s1);
    scanf("%s", s2);

    // printf("%s\n", s1);
    // printf("%s\n", s2);

    // Konversi string kedalam integer 100 digit maks
    for (s = &s1[0]; *s != '\0'; s++)
    {
        // printf("%c\n", *s);
        Push(&Stack1, *s);
    }

    for (s = &s2[0]; *s != '\0'; s++)
    {
        // printf("%c\n", *s);
        Push(&Stack2, *s);
    }

    // Algoritma perhitungan S1 - S2
    int x1, x2, x3, m;
    int carry = 0;
    Stack temp1, temp2;
    boolean swap = false;
    int sub;

    if (isSmaller(Stack1, Stack2))
    {
        temp = Stack1;
        Stack1 = Stack2;
        Stack2 = temp;
        // printf("swapped\n");
        swap = true;
    }
    int len1 = Top(Stack1) + 1;
    int len2 = Top(Stack2) + 1;

    for (i = 0; i < len2; i++)
    {
        Pop(&Stack1, &x1);
        Pop(&Stack2, &x2);
        x3 = x1 - x2 - carry;

        if (x3 < 0)
        {
            x3 += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        // printf("push1 %d\n", x3);
        Push(&Stack3, x3);
    }

    while (!IsEmpty(Stack1))
    {
        Pop(&Stack1, &x1);
        // printf("x1 : %c\n", x1);
        x3 = x1 - carry - 48;

        if (x3 < 0)
        {
            x3 += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        // printf("push2 %d\n", x3);
        Push(&Stack3, x3);
    }

    temp1 = Stack3;
    Pop(&temp1, &x3);
    if (x3 != 0)
    {
        Push(&temp1, x3);
    }
    while (x3 == 0)
    {
        Pop(&temp1, &x3);
        if (x3 != 0)
        {
            Push(&temp1, x3);
        }
    }
    Stack3 = temp1;
    if (swap)
    {
        printf("-");
    }

    while (!IsEmpty(Stack3))
    {
        Pop(&Stack3, &x1);
        printf("%i", x1);
    }
    printf("\n");

    return 0;
}