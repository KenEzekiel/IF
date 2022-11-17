#include "charmachine.h"
#include "stacklinked.h"
#include <stdio.h>

int main()
{
	Stack S;
	int val;
	int maxlength = 0;
	int csiku = 0;
	int cbiasa = 0;
	int clurus = 0;
	int ckurawal = 0;
	int ctajam = 0;
	boolean tidakvalid = false;

	CreateStack(&S);

	START();
	while (!EOP)
	{
		// printf("%c\n", currentChar);
		if (currentChar == '[')
		{
			push(&S, 0);
			DisplayStack(S);
			printf("\n");
			csiku++;
		}
		if (currentChar == ']')
		{
			if (!isEmpty(S))
			{
				if (TOP(S) == 0)
				{
					pop(&S, &val);
				}
			}
			else
			{
				tidakvalid = true;
			}
			DisplayStack(S);
			printf("\n");
		}
		if (currentChar == '(')
		{
			push(&S, 1);
			DisplayStack(S);
			printf("\n");
			cbiasa++;
		}
		if (currentChar == ')')
		{
			if (!isEmpty(S))
			{
				if (TOP(S) == 1)
				{
					pop(&S, &val);
				}
			}
			else
			{
				tidakvalid = true;
			}
			DisplayStack(S);
			printf("\n");
		}
		if (currentChar == '{')
		{
			push(&S, 3);
			DisplayStack(S);
			printf("\n");
			ckurawal++;
		}
		if (currentChar == '}')
		{
			if (!isEmpty(S))
			{
				if (TOP(S) == 3)
				{
					pop(&S, &val);
				}
			}
			else
			{
				tidakvalid = true;
			}
			DisplayStack(S);
			printf("\n");
		}
		if (currentChar == '<')
		{
			push(&S, 4);
			DisplayStack(S);
			printf("\n");
			ctajam++;
		}
		if (currentChar == '>')
		{
			if (!isEmpty(S))
			{
				if (TOP(S) == 4)
				{
					pop(&S, &val);
				}
			}
			else
			{
				tidakvalid = true;
			}
			DisplayStack(S);
			printf("\n");
		}
		if (currentChar == '|')
		{
			if (!isEmpty(S) && TOP(S) == 2)
			{
				pop(&S, &val);
			}
			else
			{
				push(&S, 2);
				clurus++;
			}
			DisplayStack(S);
			printf("\n");
		}

		if (length(S) > maxlength)
		{
			maxlength = length(S);
		}
		else
		{
			maxlength = maxlength;
		}

		ADV();
	}

	if (isEmpty(S) && !tidakvalid)
	{
		printf("kurung valid\n");
		printf("[%d] (%d) |%d| {%d} <%d>\n", csiku, cbiasa, clurus, ckurawal, ctajam);
		printf("MAX %d\n", maxlength);
	}
	else
	{
		printf("kurung tidak valid\n");
	}

	return 0;
}