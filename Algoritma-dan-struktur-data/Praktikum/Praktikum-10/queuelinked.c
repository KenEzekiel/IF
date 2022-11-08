/* File: queuelinked.c */
/* NAMA : Kenneth Ezekiel Suprantoni */
/* NIM : 13521089 */

#include "boolean.h"
#include "queuelinked.h"
#include <stdlib.h>
#include <stdio.h>

//#define NIL NULL
/* Deklarasi infotype */
// typedef int ElType;
/* Queue dengan representasi berkait dengan pointer */
// typedef struct node *Address;
// typedef struct node
//{
//     ElType info;
//     Address next;
// } Node;
/* Type queue dengan ciri HEAD dan TAIL: */
// typedef struct
//{
//     Address addrHead; /* alamat penghapusan */
//     Address addrTail; /* alamat penambahan */
// } Queue;

/* Selektor */
/*
#define NEXT(p) (p)->next
#define INFO(p) (p)->info

#define ADDR_HEAD(q) (q).addrHead
#define ADDR_TAIL(q) (q).addrTail
#define HEAD(q) (q).addrHead->info
*/

/* Prototype manajemen memori */
Address newNode(ElType x)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
   atau NIL jika alokasi gagal */

boolean isEmpty(Queue q)
{
    return ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL;
}
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */

int length(Queue q)
{
    // KAMUS LOKAL
    int cnt = 0;
    Address p = ADDR_HEAD(q);
    // ALGORITMA
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        while (p != NULL)
        {
            cnt += 1;
            p = NEXT(p);
        }
        return cnt;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateQueue(Queue *q)
{
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */

void DisplayQueue(Queue q)
{
    // KAMUS LOKAL
    Address p = ADDR_HEAD(q);
    ElType val;
    // ALGORITMA
    printf("[");
    if (!isEmpty(q))
    {
        while (p != NULL)
        {
            val = INFO(p);
            if (NEXT(p) != NULL)
            {
                printf("%d,", val);
            }
            else
            {
                printf("%d", val);
            }
            p = NEXT(p);
        }
    }
    printf("]");
}
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah,
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x)
{
    // KAMUS LOKAL
    Address p = ADDR_TAIL(*q);
    Address new = newNode(x);
    // ALGORITMA
    NEXT(p) = new;
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */

void dequeue(Queue *q, ElType *x)
{
    // KAMUS LOKAL
    Address p = ADDR_HEAD(*q);
    Address new = NEXT(p);
    // ALGORITMA
    *x = HEAD(*q);
    ADDR_HEAD(*q) = new;
    free(p);
}
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
