#include "queuelinked.h"
#include "charmachine.h"
#include <stdio.h>
#include "boolean.h"

boolean isElHomogen(Queue Q) {
    Address P = ADDR_HEAD(Q);
    int x = INFO(P); 
    while (P != NULL) {
        if (INFO(P) != x) {
            return false;
        }
        P = NEXT(P);
    }
    return true;
}
int main() {
    START();
    Queue S, mhs, stok;
    int ctr = 0;

    CreateQueue(&S);
    CreateQueue(&mhs);
    CreateQueue(&stok);

    // isi stack request mahasiswa
    while (currentChar != ',') {
        if (currentChar == 'B') {
            enqueue(&mhs, 0);
        } 
        else if (currentChar == 'K'){
            enqueue(&mhs, 1);
        }
        ctr++;
        enqueue(&stok, ctr);
        ADV();
    }
    ADV();

    //isi stack stock bntk sandwich
    while (!EOP) {
        if (currentChar == 'B') {
            enqueue(&S, 0);
        } 
        else if (currentChar == 'K') {
            enqueue(&S, 1);
        }
        ADV();
    }

    int nmhs, shape;
    while (!isEmpty(S) && !(isElHomogen(mhs) && HEAD(mhs) != HEAD(S))) {
        if (HEAD(S) == HEAD(mhs)) {
            dequeue(&S, &shape);
            dequeue(&mhs, &shape);
            dequeue(&stok, &nmhs);

            if (shape == 0) {
                printf("%d -> bulat\n", nmhs);
            } 
            else {
                printf("%d -> kotak\n", nmhs);
            }
            
        } 
        else {
            dequeue(&mhs, &shape);
            enqueue(&mhs, shape);
            dequeue(&stok, &nmhs);
            enqueue(&stok, nmhs);
        }
    }
    printf("%d\n", length(S));
    return 0;
}