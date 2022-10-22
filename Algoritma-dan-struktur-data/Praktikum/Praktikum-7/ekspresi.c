#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"
#include "stack.h"
#include <math.h>

void displayWord(Word kata)
{
    int i;
    for (i = 0; i < kata.Length; i++)
    {
        printf("%c", kata.TabWord[i]);
    }
    printf("\n");
}
int getValue(Word kata)
{
    int i, val, m;
    val = 0;
    m = 1;
    for (i = kata.Length - 1; i >= 0; i--)
    {
        val += (kata.TabWord[i] - '0') * m;
        m *= 10;
    }
    return val;
}

int main()
{

    int i;
    Stack S;
    int x1, x2, x3;
    CreateEmpty(&S);

    STARTWORD();
    if (endWord)
    {
        printf("Ekspresi kosong\n");
    }
    else
    {
        while (!endWord)
        {
            if (currentWord.TabWord[0] == '+' || currentWord.TabWord[0] == '-' || currentWord.TabWord[0] == '*' || currentWord.TabWord[0] == '/' || currentWord.TabWord[0] == '^')
            {
                Pop(&S, &x2);
                Pop(&S, &x1);
                printf("%d %c %d\n", x1, currentWord.TabWord[0], x2);
                if (currentWord.TabWord[0] == '+')
                {
                    x3 = x1 + x2;
                }
                if (currentWord.TabWord[0] == '-')
                {
                    x3 = x1 - x2;
                }
                if (currentWord.TabWord[0] == '*')
                {
                    x3 = x1 * x2;
                }
                if (currentWord.TabWord[0] == '/')
                {
                    x3 = x1 / x2;
                }
                if (currentWord.TabWord[0] == '^')
                {
                    x3 = (int)pow(x1, x2);
                }
                printf("%d\n", x3);
                Push(&S, x3);
            }
            else
            {
                displayWord(currentWord);
                Push(&S, getValue(currentWord));
            }
            ADVWORD();
        }
        Pop(&S, &x3);
        printf("Hasil=%d\n", x3);
    }

    return 0;
}