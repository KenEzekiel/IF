/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */
// NAMA : Kenneth Ezekiel
// NIM : 13521089

#include "listlinier.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* Definisi Node : */
/*typedef int ElType;
typedef struct node *Address;
typedef struct node
{
    ElType info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next*/

Address newNode(ElType val)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

// typedef Address List;

//#define IDX_UNDEF (-1)
//#define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
{
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
{
    /* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
{
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengembalikan nilai elemen l pada indeks idx */
    // KAMUS LOKAL
    int i = 0;
    List p = l;

    // ALGORITMA
    while (i < idx)
    {
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val)
{
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    // KAMUS LOKAL
    int i = 0;
    Address p = *l;

    // ALGORITMA
    while (i < idx)
    {
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val)
{
    /* I.S. l, val terdefinisi */
    /* F.S. Mencari apakah ada elemen list l yang bernilai val */
    /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
    /* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    // KAMUS LOKAL
    List p = l;
    int i = 0;
    boolean found = false;

    // ALGORITMA
    while ((p != NULL) && (!found))
    {
        if (INFO(p) == val)
        {
            found = true;
        }
        else
        {
            p = NEXT(p);
            i++;
        }
    }

    if (found)
    {
        return i;
    }
    else
    {
        return IDX_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
{
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
    /* Jika alokasi gagal: I.S.= F.S. */
    // KAMUS LOKAL
    Address p;

    // ALGORITMA
    p = newNode(val);
    if (p == NULL)
    {
    }
    else
    {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val)
{
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    // KAMUS LOKAL
    Address p, q;

    // ALGORITMA
    q = *l;
    p = newNode(val);
    if (p == NULL)
    {
    }
    else
    {
        if (isEmpty(*l))
        {
            insertFirst(l, val);
        }
        else
        {
            while (NEXT(q) != NULL)
            {
                q = NEXT(q);
            }
            NEXT(q) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx)
{
    /* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
    /* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    // KAMUS LOKAL
    Address p, q;
    int i = 0;

    // ALGORITMA
    q = *l;
    p = newNode(val);
    if (p == NULL)
    {
    }
    else
    {
        if (idx == 0)
        {
            insertFirst(l, val);
        }
        else
        {
            while (i < idx - 1)
            {
                i++;
                q = NEXT(q);
            }
            NEXT(p) = NEXT(q);
            NEXT(q) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
{
    /* I.S. List l tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen pertama di-dealokasi */
    // KAMUS LOKAL
    Address p = *l;

    // ALGORITMA
    *val = INFO(p);
    if (NEXT(p) == NULL)
    {
        *l = NULL;
        free(*l);
        CreateList(l);
    }
    else
    {
        *l = NEXT(p);
        free(p);
    }
}
void deleteLast(List *l, ElType *val)
{
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen terakhir di-dealokasi */
    // KAMUS LOKAL
    Address p, q;

    // ALGORITMA
    if (NEXT(*l) == NULL)
    {
        deleteFirst(l, val);
    }
    else
    {
        p = *l;
        q = NULL;
        while (NEXT(p) != NULL)
        {
            q = p;
            p = NEXT(p);
        }
        if (q == NULL)
        {
            *l = NULL;
        }
        else
        {
            NEXT(q) = NULL;
        }
        *val = INFO(p);
        free(p);
    }
}

void deleteAt(List *l, int idx, ElType *val)
{
    /* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. val diset dengan elemen l pada indeks ke-idx. */
    /*      Elemen l pada indeks ke-idx dihapus dari l */
    // KAMUS LOKAL
    Address p, q;
    int i = 0;

    // ALGORITMA
    if (NEXT(*l) == NULL)
    {
        deleteFirst(l, val);
    }
    else
    {
        if (idx == 0)
        {
            deleteFirst(l, val);
        }
        else
        {
            p = *l;
            while (i < idx)
            {
                q = p;
                p = NEXT(p);
                i++;
            }
            *val = INFO(p);
            NEXT(q) = NEXT(p);
            NEXT(p) = NULL;
            free(p);
        }
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
{
    // void printInfo(List l);
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    // KAMUS LOKAL
    Address p;

    // ALGORITMA
    p = l;

    printf("[");

    if (!isEmpty(l))
    {
        while (NEXT(p) != NULL)
        {
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO(p));
    }

    printf("]");
}

int length(List l)
{
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    // KAMUS LOKAL
    int count = 0;
    Address p;

    // ALGORITMA
    p = l;
    if (isEmpty(l))
    {
        return count;
    }
    else
    {
        count = 1;
        while (NEXT(p) != NULL)
        {
            p = NEXT(p);
            count++;
        }
        return count;
    }
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
{
    /* I.S. l1 dan l2 sembarang */
    /* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
    /* Konkatenasi dua buah list : l1 dan l2    */
    /* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
    /* Tidak ada alokasi/dealokasi pada prosedur ini */
    // KAMUS LOKAL
    Address p;
    List l3;
    ElType val;

    // ALGORITMA
    /*CreateList(&l3);
    if (isEmpty(l1))
    {
        FIRST(l3) = FIRST(l2);
    }
    else
    {
        FIRST(l3) = FIRST(l1);
        p = l3;
        while (NEXT(p) != NULL)
        {
            p = NEXT(p);
        }
        NEXT(p) = FIRST(l2);
    }
    FIRST(l1) = NULL;
    FIRST(l2) = NULL;
    return l3;*/

    CreateList(&l3);
    p = l1;
    while (p != NULL)
    {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p != NULL)
    {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    return l3;
}

// Pencarian sebuah elemen

boolean fSearch(List l, Address p)
{
    /* Mencari apakah ada elemen list yang beralamat P */
    /* Mengirimkan true jika ada, false jika tidak ada */
    // KAMUS LOKAL
    Address q = l;
    boolean found = false;
    // ALGORITMA
    while ((q != NULL) && (!found))
    {
        if (INFO(q) == INFO(p))
        {
            found = true;
        }
        q = NEXT(q);
    }
    return found;
}

Address searchPrec(List l, ElType x)
{
    /* Mengirimkan address elemen sebelum elemen yang nilainya=X */
    /* Mencari apakah ada elemen list dengan Info(P)=X */
    /* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
    /* Jika tidak ada, mengirimkan Nil */
    /* Jika P adalah elemen pertama, maka Prec=Nil */
    /* Search dengan spesifikasi seperti ini menghindari */
    /* traversal ulang jika setelah Search akan dilakukan operasi lain */
    // KAMUS LOKAL
    int idx = indexOf(l, x);
    Address p = l;
    Address q;
    int i;

    // ALGORITMA
    if (idx == IDX_UNDEF)
    {
        return NULL;
    }
    else
    {
        if (idx == 0)
        {
            return NULL;
        }
        else
        {
            for (i = 0; i < idx; i++)
            {
                p = NEXT(p);
            }
            return p;
        }
    }
}

// Pencarian Nilai Ekstrim dan Rata-Rata (prekondisi: list tidak kosong)

ElType max(List l)
{
    /* Mengirimkan nilai info(P) yang maksimum */
    // KAMUS LOKAL
    ElType max = INFO(l);
    Address p = l;
    // ALGORITMA
    while (p != NULL)
    {
        if (INFO(p) > max)
        {
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return max;
}

Address adrMax(List l)
{
    /* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    // KAMUS LOKAL
    ElType max = INFO(l);
    Address p = l;
    Address q;
    // ALGORITMA
    while (p != NULL)
    {
        if (INFO(p) > max)
        {
            q = p;
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return q;
}

ElType min(List l)
{
    /* Mengirimkan nilai info(P) yang minimum */
    // KAMUS LOKAL
    ElType min = INFO(l);
    Address p = l;
    // ALGORITMA
    while (p != NULL)
    {
        if (INFO(p) < min)
        {
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return min;
}

Address adrMin(List l)
{
    /* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    // KAMUS LOKAL
    ElType min = INFO(l);
    Address p = l;
    Address q;
    // ALGORITMA
    while (p != NULL)
    {
        if (INFO(p) < min)
        {
            q = p;
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return q;
}

// Proses terhadap semua elemen list

void deleteAll(List *l)
{
    // KAMUS LOKAL
    Address p = *l;
    ElType val;
    // ALGORITMA
    while (!isEmpty(*l))
    {
        deleteLast(l, &val);
    }
}

void copyList(List *l1, List *l2)
{
    // KAMUS LOKAL
    Address p = *l1;
    // ALGORITMA
    *l2 = *l1;
}

void inverseList(List *l)
{
    // KAMUS LOKAL
    Address prev = NULL;
    Address cur = *l;
    Address next = NULL;
    List l1;

    // ALGORITMA
    while (cur != NULL)
    {
        next = NEXT(cur);
        NEXT(cur) = prev;
        prev = cur;
        cur = next;
    }
    *l = prev;
}

void splitList(List *l1, List *l2, List l)
{
    // KAMUS LOKAL
    int split;
    int len = length(l);
    int i = 1;
    Address p = l;
    // ALGORITMA
    CreateList(l1);
    CreateList(l2);
    split = len / 2;

    while (p != NULL)
    {
        if (i <= split)
        {
            insertLast(l1, INFO(p));
        }
        else
        {
            insertLast(l2, INFO(p));
        }
        p = NEXT(p);
        i++;
    }
}
