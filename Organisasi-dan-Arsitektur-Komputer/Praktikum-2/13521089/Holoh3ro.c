void Holoh3ro(char *input)
{
    int a, b;
    int var;
    int i = read_two_number(input, &a, &b);
    if (i < 2)
    {
        illegal_move();
    }
    switch (a)
    {
    case 0:
        var = 989;
        break;
    case 1:
        var = 373;
        break;
    case 2:
        var = 781;
        break;
    case 3:
        var = 508;
        break;
    case 4:
    case 5:
        var = 741;
        break;
    case 6:
        var = 693;
        break;
    case 7:
        var = 606;
        illegal_move();
    default:
        var = 0;
    }
    if (var + b != 0)
    {
        illegal_move();
    }
}
