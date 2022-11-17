#define true 1
#define false 0

void Uncover_Corps_Basement(char *input)
{
    int bool = strings_not_equal(input, "PEKORA PEKO DOUMO DOUMO");
    if (bool != false)
    {
        illegal_move();
    }
    return;
}

int strings_not_equal(char *input1, char *input2)
{
    int len1 = string_length(input1);
    int len2 = string_length(input2);
    int retval = false;

    if (len1 == len2)
    {
        char c = *input1;
        if (c == '\0')
        {
            retval = false;
        }
        else
        {
            while (c != '\0')
            {
                if (*input2 != c)
                {
                    retval = true;
                }
                input1++;
                input2++;
                c = *input1;
            }
        }
    }
    else
    {
        retval = true;
    }
    return retval;
}

int string_length(char *input)
{
    int len = 0;
    if (*input != '\0')
    {
        while (input[len] != '\0')
        {
            len++;
        }
    }
    return len;
}