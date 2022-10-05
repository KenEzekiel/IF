#include "wordmachine.h"
#include <stdio.h>

int main()
{
    int longest = 0;

    STARTWORD();

    while (!EndWord)
    {
        if (longest < currentWord.Length)
        {
            longest = currentWord.Length;
        }
        ADVWORD();
    }
    printf("%d\n", longest);
}