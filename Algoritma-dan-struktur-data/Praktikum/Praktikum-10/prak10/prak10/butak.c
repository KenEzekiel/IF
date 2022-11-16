#include "charmachine.h"
#include "queuelinked.h"
#include <stdio.h>

boolean isElHomogen(Queue q)
{
	// // KAMUS LOKAL
	// Address p = ADDR_HEAD(q);
	// ElType info = HEAD(q);
	// ElType val;
	// boolean homogen = true;
	// // ALGORITMA
	// if (!isEmpty(q))
	// {
	// 	while (p != NULL && homogen)
	// 	{
	// 		val = INFO(p);
	// 		if (info != val)
	// 		{
	// 			homogen = false;
	// 		}
	// 		p = NEXT(p);
	// 	}
	// }

	// return homogen;
	// KAMUS LOKAL
	boolean homogen = true;
	ElType val = HEAD(q);
	Address p = ADDR_HEAD(q);
	// ALGORITMA
	if (NEXT(p) == NULL)
	{
		return true;
	}
	else
	{
		while (NEXT(p) != NULL && homogen)
		{
			p = NEXT(p);
			if (val != INFO(p))
			{
				homogen = false;
			}
		}
		return homogen;
	}
}

int main()
{
	Queue qpref, qno, qmakanan;
	boolean udahKoma = false;
	int nomor = 1;
	ElType mhs, mkn;
	int tempno;
	boolean condition = true;

	CreateQueue(&qpref);
	CreateQueue(&qno);
	CreateQueue(&qmakanan);

	START();
	while (!EOP)
	{

		if (!udahKoma && currentChar == ',')
		{
			udahKoma = true;
		}
		else if (!udahKoma)
		{
			if (currentChar == 'B')
			{
				enqueue(&qpref, 0);
				enqueue(&qno, nomor);
				nomor++;
			}
			if (currentChar == 'K')
			{
				enqueue(&qpref, 1);
				enqueue(&qno, nomor);
				nomor++;
			}
		}
		else
		{
			if (currentChar == 'B')
			{
				enqueue(&qmakanan, 0);
			}
			if (currentChar == 'K')
			{
				enqueue(&qmakanan, 1);
			}
		}

		ADV();
	}

	while (condition)
	{
		// dequeue(&qpref, &mhs);
		// dequeue(&qno, &tempno);
		mhs = HEAD(qpref);
		tempno = HEAD(qno);

		if (mhs == HEAD(qmakanan))
		{
			// printf("\nserved\n");
			dequeue(&qmakanan, &mkn);
			dequeue(&qpref, &mhs);
			dequeue(&qno, &tempno);
			printf("%d -> ", tempno);
			if (mkn == 0)
			{
				printf("bulat\n");
			}
			else
			{
				printf("kotak\n");
			}
		}
		else
		{
			// DisplayQueue(qpref);
			// printf("\nmhs %d\n", mhs);
			enqueue(&qpref, mhs);
			// printf("\nC\n");
			enqueue(&qno, tempno);
			dequeue(&qpref, &mhs);
			dequeue(&qno, &tempno);
		}
		// printf("\nqpref qmakanan : ");
		// DisplayQueue(qpref);
		// DisplayQueue(qmakanan);
		// printf("\n");
		// printf("is qpref empty? %d\n", isEmpty(qpref));

		if (isEmpty(qpref))
		{
			break;
		}
		if (HEAD(qpref) == 1 && isElHomogen(qpref))
		{
			if (HEAD(qmakanan) == 0)
			{
				condition = false;
			}
		}
		else if (HEAD(qpref) == 0 && isElHomogen(qpref))
		{
			if (HEAD(qmakanan) == 1)
			{
				condition = false;
			}
		}
	}
	if (isEmpty(qpref))
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", length(qpref));
	}

	return 0;
}

// int main()
// {
// 	Queue Q;
// 	CreateQueue(&Q);
// 	enqueue(&Q, 1);
// 	enqueue(&Q, 1);

// 	printf("homogen? %d\n", isElHomogen(Q));
// }