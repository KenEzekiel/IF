/*Pra Praktikum List Dinamik*/
/*Nama : Kenneth Ezekiel
NIM : 13521089*/

/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "listdin.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
{
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealocateList(ListDin *l)
{
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l)
{
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    return NEFF(l);
}
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}
IdxType getLastIdx(ListDin l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    return (IdxType)(listLength(l) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= IDX_MIN) && (i <= (IdxType)CAPACITY(l) - 1);
}
boolean isIdxEff(ListDin l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 0..NEFF(l) */
    return (i >= IDX_MIN) && (i <= NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
{
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    return (listLength(l) == 0);
}
/* *** Test list penuh *** */
boolean isFull(ListDin l)
{
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return (listLength(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
{
    /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
    /* F.S. List l terdefinisi */
    /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
          0 satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk l kosong */
    /*KAMUS LOKAL*/
    int N;
    IdxType i;
    boolean valid = false;
    ElType elm;
    /*ALGORITMA*/
    while (valid != true)
    {
        scanf("%d", &N);

        if ((N >= 0) && (N <= CAPACITY(*l)))
        {
            valid = true;
        }
    }
    NEFF(*l) = N;

    if (N > 0)
    {
        for (i = 0; i <= (IdxType)N - 1; i++)
        {
            scanf("%d", &elm);
            ELMT(*l, i) = elm;
        }
    }
}
void printList(ListDin l)
{
    /* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
       antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
       di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /*KAMUS LOKAL*/
    IdxType i;
    /*ALGORITMA*/
    printf("[");
    for (i = 0; i <= NEFF(l) - 1; i++)
    {
        printf("%d", ELMT(l, i));
        if (i != NEFF(l) - 1)
        {
            printf(",");
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    /* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    /*KAMUS LOKAL*/
    ListDin LHasil;
    IdxType i;
    /*ALGORITMA*/
    CreateListDin(&LHasil, NEFF(l1));
    for (i = 0; i <= NEFF(l1) - 1; i++)
    {
        if (plus == true)
        {
            ELMT(LHasil, i) = ELMT(l1, i) + ELMT(l2, i);
        }
        else
        {
            ELMT(LHasil, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    NEFF(LHasil) = NEFF(l1);
    return LHasil;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
{
    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    /*KAMUS LOKAL*/
    boolean equal = true;
    int i = 0;
    /*ALGORITMA*/
    if (NEFF(l1) == NEFF(l2))
    {
        while ((equal == true) && (i <= NEFF(l1) - 1))
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                equal = false;
            }
            i++;
        }
    }
    else
    {
        equal = false;
    }
    return equal;
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
{
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
    /* Jika tidak ada, mengirimkan IDX_UNDEF */
    /* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
    /* Skema Searching yang digunakan bebas */
    /*KAMUS LOKAL*/
    int i = 0;
    boolean found = false;
    IdxType idx;
    /*ALGORITMA*/
    while ((found != true) && (i <= NEFF(l) - 1))
    {
        if (ELMT(l, i) == val)
        {
            found = true;
            idx = i;
        }
        i++;
    }
    return idx;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min)
{
    /* I.S. List l tidak kosong */
    /* F.S. max berisi nilai maksimum l;
            min berisi nilai minimum l */
    /*KAMUS LOKAL*/
    ElType maxval, minval;
    int i;
    /*ALGORITMA*/
    maxval = ELMT(l, 0);
    minval = ELMT(l, 0);
    for (i = 0; i <= NEFF(l) - 1; i++)
    {
        if (ELMT(l, i) > maxval)
        {
            maxval = ELMT(l, i);
        }
        if (ELMT(l, i) < minval)
        {
            minval = ELMT(l, i);
        }
    }
    *max = maxval;
    *min = minval;
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
{
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i <= NEFF(lIn) - 1; i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}
ElType sumList(ListDin l)
{
    /* Menghasilkan hasil penjumlahan semua elemen l */
    /* Jika l kosong menghasilkan 0 */
    /*KAMUS LOKAL*/
    ElType sum = 0;
    IdxType i;
    /*ALGORITMA*/
    for (i = 0; i <= NEFF(l) - 1; i++)
    {
        sum = sum + ELMT(l, i);
    }
    return sum;
}
int countVal(ListDin l, ElType val)
{
    /* Menghasilkan berapa banyak kemunculan val di l */
    /* Jika l kosong menghasilkan 0 */
    /*KAMUS LOKAL*/
    int count = 0;
    int i;
    /*ALGORITMA*/
    for (i = 0; i <= NEFF(l) - 1; i++)
    {
        if (ELMT(l, i) == val)
        {
            count++;
        }
    }
    return count;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
{
    /* I.S. l boleh kosong */
    /* F.S. Jika asc = true, l terurut membesar */
    /*      Jika asc = false, l terurut mengecil */
    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
       algoritma bebas */
    /*Menggunakan Insertion Sort*/
    /*KAMUS LOKAL*/
    int i, j;
    ElType temp;
    IdxType idx;
    /*ALGORITMA*/
    if (asc == true)
    {
        for (i = 1; i <= NEFF(*l) - 1; i++)
        {
            temp = ELMT(*l, i);
            idx = i - 1;
            while ((temp < ELMT(*l, idx)) && (idx > 0))
            {
                ELMT(*l, idx + 1) = ELMT(*l, idx);
                idx--;
            }
            if (temp >= ELMT(*l, idx))
            {
                ELMT(*l, idx + 1) = temp;
            }
            else
            {
                ELMT(*l, idx + 1) = ELMT(*l, idx);
                ELMT(*l, idx) = temp;
            }
        }
    }
    else
    {
        for (i = 1; i <= NEFF(*l) - 1; i++)
        {
            temp = ELMT(*l, i);
            idx = i - 1;
            while ((temp > ELMT(*l, idx)) && (idx > 0))
            {
                ELMT(*l, idx + 1) = ELMT(*l, idx);
                idx--;
            }
            if (temp <= ELMT(*l, idx))
            {
                ELMT(*l, idx + 1) = temp;
            }
            else
            {
                ELMT(*l, idx + 1) = ELMT(*l, idx);
                ELMT(*l, idx) = temp;
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
{
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    if (isFull(*l) != true)
    {
        i = NEFF(*l);
        ELMT(*l, i) = val;
        NEFF(*l)
        ++;
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
{
    /* Proses : Menghapus elemen terakhir list */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen list berkurang satu */
    /*      List l mungkin menjadi kosong */
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    if (isEmpty(*l) != true)
    {
        *val = ELMT(*l, getLastIdx(*l));
        NEFF(*l)
        --;
    }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num)
{
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */
    /*KAMUS LOKAL*/
    ListDin LTemp;
    int i;
    /*ALGORITMA*/
    CreateListDin(&LTemp, CAPACITY(*l) + num);
    for (i = 0; i <= NEFF(*l) - 1; i++)
    {
        ELMT(LTemp, i) = ELMT(*l, i);
    }
    NEFF(LTemp) = NEFF(*l);

    dealocateList(l);
    copyList(LTemp, l);
}

void shrinkList(ListDin *l, int num)
{
    /* Proses : Mengurangi capacity sebanyak num */
    /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
    /* F.S. Ukuran list berkurang sebanyak num. */
    /*KAMUS LOKAL*/
    ListDin LTemp;
    int i;
    /*ALGORITMA*/
    CreateListDin(&LTemp, CAPACITY(*l) - num);
    for (i = 0; i <= NEFF(*l) - 1; i++)
    {
        ELMT(LTemp, i) = ELMT(*l, i);
    }
    NEFF(LTemp) = NEFF(*l);
    dealocateList(l);
    copyList(LTemp, l);
}

void compressList(ListDin *l)
{
    /* Proses : Mengubah capacity sehingga nEff = capacity */
    /* I.S. List tidak kosong */
    /* F.S. Ukuran nEff = capacity */
    /*KAMUS LOKAL*/
    ListDin LTemp;
    int i;
    /*ALGORITMA*/
    CreateListDin(&LTemp, NEFF(*l));
    for (i = 0; i <= NEFF(*l) - 1; i++)
    {
        ELMT(LTemp, i) = ELMT(*l, i);
    }
    NEFF(LTemp) = NEFF(*l);
    dealocateList(l);
    copyList(LTemp, l);
}
