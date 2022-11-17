

void Holoro(char *input)
{
    int a[6];
    read_six_numbers(input, a);
    if (a[0] != 1)
    {
        illegal_move();
    }
    unsigned int v = 1;
    int bool = 1;

    for (int i = 0; i < 6; i++)
    {
        if (a[i] != function(i + 1))
        {
            bool = 0;
        }
    }
    if (bool == 0)
    {
        illegal_move();
    }
}

int function(int suku)
{
    if (suku == 1)
    {
        return 1;
    }
    else if (suku == 2)
    {
        return 2;
    }
    else
    {
        if (suku % 2 == 0)
        {
            return (suku - 1) + function(suku - 1);
        }
        else
        {
            return (suku - 1) * function(suku - 1);
        }
    }
}
