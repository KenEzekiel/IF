void Area15(char *input)
{
    int num1, num2;
    int var;
    int c = read_two_number(input, &num1, &num2);
    if (c < 2)
    {
        illegal_move();
    }
    num1 = num1 & 0xf;
    if (num1 == 0xf)
    {
        illegal_move();
    }
    int a[16];
    a[0] = 13;
    a[1] = 12;
    a[2] = 4;
    a[3] = 5;
    a[4] = 14;
    a[5] = 7;
    a[6] = 1;
    a[7] = 9;
    a[8] = 11;
    a[9] = 0;
    a[10] = 2;
    a[11] = 3;
    a[12] = 10;
    a[13] = 15;
    a[14] = 8;
    a[15] = 6;

    int val = 0;
    int count = 0;
    while (num1 != 15)
    {
        count++;
        val += a[num1];
        num1 = a[num1];
    }
    if (!(count == 15 && num2 == val))
    {
        illegal_move();
    }
}