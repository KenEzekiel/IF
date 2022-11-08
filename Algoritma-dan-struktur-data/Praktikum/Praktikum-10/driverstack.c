#include "stacklinked.h"
#include <stdio.h>

int main()
{
    Stack s;
    CreateStack(&s);

    printf("is it empty? %d\n", isEmpty(s));
    printf("length? %d\n", length(s));
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    DisplayStack(s);
    int val;
    pop(&s, &val);
    DisplayStack(s);

    return 0;
}
