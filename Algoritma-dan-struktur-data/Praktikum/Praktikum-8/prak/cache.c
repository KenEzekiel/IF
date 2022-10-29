#include "listlinier.h"
#include <stdio.h>

int main() {
	int i;
	float counthit = 0;
	float countmiss = 0;
	int N;
	scanf("%d", &N);
	int Q;
	scanf("%d", &Q);
	
	
	float ratio;
	ElType x, temp;
	
	List L;
	
	CreateList(&L);
	for (i = 0; i < Q; i++) {
		scanf("%d", &x);
		if (isEmpty(L)) {
			countmiss++;
			insertFirst(&L, x);
			printf("miss ");
			displayList(L);
			printf("\n");
		} else if (indexOf(L, x) != IDX_UNDEF) {
			counthit++;
			deleteAt(&L, indexOf(L, x), &temp);
			insertFirst(&L, x);
			printf("hit ");
			displayList(L);
			printf("\n");
		} else if (length(L) == N) {
			countmiss++;
			deleteLast(&L, &temp);
			insertFirst(&L, x);
			printf("miss ");
			displayList(L);
			printf("\n");
		} else {
			countmiss++;
			insertFirst(&L, x);
			printf("miss ");
			displayList(L);
			printf("\n");
		}
	}
	
	printf("hit ratio: ");
	if (counthit == 0) {
		ratio = 0;
		printf("%.2f\n", ratio);
	} else {
		ratio = counthit / (counthit + countmiss);
		printf("%.2f\n", ratio);
	}
} 
