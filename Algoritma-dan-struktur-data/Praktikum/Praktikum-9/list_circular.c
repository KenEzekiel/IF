/* File : list_circular.c */
/* NAMA : Kenneth Ezekiel Suprantoni */
/* NIM : 13521089 */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan Address adalah pointer */
/* ElType adalah integer */

#include "boolean.h"
#include "list_circular.h"
#include <stdlib.h>
#include <stdio.h>

/*
typedef int ElType;
typedef struct node *Address;
typedef struct node {
    ElType info;
    Address next;
} ElmtList;
typedef struct {
    Address first;
} List;
*/

/* Definisi List Circular : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), NEXT(P) */
/* Elemen terakhir list: jika Addressnya Last, maka NEXT(Last)=FIRST(l) */

/* Selektor */
//#define INFO(P) (P)->info
//#define NEXT(P) (P)->next
//#define FIRST(l) ((l).first)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
{
    /* Mengirim true jika list kosong. Lihat definisi di atas. */
    return FIRST(l) == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
{
    /* I.S. l sembarang             */
    /* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val)
{
    /* Mengirimkan Address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
    /* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
    /* Jika alokasi gagal, mengirimkan NULL */
    Address p = (Address)malloc(sizeof(ElmtList));
    if (p != NULL)
    {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
void deallocate(Address P)
{
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian Address P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
{
    /* Mencari apakah ada elemen list dengan INFO(P)= val */
    /* Jika ada, mengirimkan Address elemen tersebut. */
    /* Jika tidak ada, mengirimkan NULL */
    // KAMUS LOKAL
    Address p = FIRST(l);
    Address ret = NULL;
    boolean found = false;
    // ALGORITMA
    while (NEXT(p) != FIRST(l) && !found)
    {
        if (INFO(p) == val)
        {
            ret = p;
            found = true;
        }
        else
        {
            p = NEXT(p);
        }
    }
    if (!found)
    {
        if (INFO(p) == val)
        {
            ret = p;
        }
    }
    return ret;
}

boolean addrSearch(List l, Address p)
{
    /* Mencari apakah ada elemen list l yang beralamat p */
    /* Mengirimkan true jika ada, false jika tidak ada */
    // KAMUS LOKAL
    Address q = FIRST(l);
    boolean found = false;
    // ALGORITMA
    while (NEXT(q) != FIRST(l) && !found)
    {
        if (q == p)
        {
            found = true;
        }
        else
        {
            q = NEXT(q);
        }
    }
    if (!found)
    {
        if (q == p)
        {
            found = true;
        }
    }
    return found;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
{
    /* I.S. List l terdefinisi, mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
    /* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */
    // KAMUS LOKAL
    Address p = allocate(val);
    Address q = FIRST(*l);
    // ALGORITMA
    if (p != NULL)
    {
        if (isEmpty(*l))
        {
            FIRST(*l) = p;
            NEXT(FIRST(*l)) = FIRST(*l);
        }
        else
        {
            while (NEXT(q) != FIRST(*l))
            {
                q = NEXT(q);
            }
            // NEXT(q) = FIRST(*l)
            NEXT(q) = p;

            NEXT(p) = FIRST(*l);
            FIRST(*l) = p;
        }
    }
}
void insertLast(List *l, ElType val)
{
    /* I.S. List l terdefinisi, mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */
    // KAMUS LOKAL
    Address p = allocate(val);
    Address q = FIRST(*l);
    // ALGORITMA
    if (p != NULL)
    {
        if (isEmpty(*l))
        {
            insertFirst(l, val);
        }
        else
        {
            while (NEXT(q) != FIRST(*l))
            {
                q = NEXT(q);
            }
            // NEXT(q) = FIRST(*l)
            NEXT(q) = p;

            NEXT(p) = FIRST(*l);
        }
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
{
    /* I.S. List l tidak kosong  */
    /* F.S. val adalah elemen pertama List l sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /*      First element yg baru adalah suksesor elemen pertama yang lama */
    /*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
    /*      Jika list baru kosong, maka FIRST(*l) = NULL */
    /*      Alamat elemen pertama list lama di-dealokasi */
    // KAMUS LOKAL
    Address p = FIRST(*l);
    // ALGORITMA
    *val = INFO(p);
    if (NEXT(FIRST(*l)) == FIRST(*l))
    {
        FIRST(*l) = NULL;
    }
    else
    {

        FIRST(*l) = NEXT(p);
        deallocate(p);
    }
}
void deleteLast(List *l, ElType *val)
{
    /* I.S. List l tidak kosong */
    /* F.S. val adalah elemen terakhir list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
    /*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
    /*      Jika list baru kosong, maka FIRST(*l) = NULL */
    /*      Alamat elemen terakhir list lama di-dealokasi */
    // KAMUS LOKAL
    Address p = FIRST(*l);
    Address q;
    // ALGORITMA

    if (NEXT(p) == FIRST(*l))
    {
        deleteFirst(l, val);
    }
    else
    {
        while (NEXT(p) != FIRST(*l))
        {
            q = p;
            p = NEXT(p);
        }
        *val = INFO(p);
        NEXT(q) = FIRST(*l);
        deallocate(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
{
    /* I.S. List l mungkin kosong */
    /* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    // KAMUS LOKAL
    Address p;

    // ALGORITMA
    p = FIRST(l);

    printf("[");

    if (!isEmpty(l))
    {
        while (NEXT(p) != FIRST(l))
        {
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO(p));
    }

    printf("]");
}