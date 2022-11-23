#include <stdio.h>
#include "listrec.h"
#include <stdlib.h>

/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
ElType maxList(List l)
{
    if (isOneElmt(l))
    {
        return head(l);
    }
    else
    {
        int var = maxList(tail(l));
        if (head(l) > var)
        {
            return head(l);
        }
        else
        {
            return var;
        }
    }
}
/* Mengirimkan nilai INFO(p) yang maksimum */

ElType minList(List l)
{
    if (isOneElmt(l))
    {
        return head(l);
    }
    else
    {
        int var = maxList(tail(l));
        if (head(l) < var)
        {
            return head(l);
        }
        else
        {
            return var;
        }
    }
}
/* Mengirimkan nilai INFO(p) yang minimum */

ElType sumList(List l)
{
    if (isOneElmt(l))
    {
        return head(l);
    }
    else
    {
        return head(l) + sumList(tail(l));
    }
}
/* Mengirimkan total jumlah elemen List l */

float averageList(List l)
{
    if (isOneElmt(l))
    {
        return head(l);
    }
    else
    {
        return (head(l) + averageList(tail(l))) / 2;
    }
}
/* Mengirimkan nilai rata-rata elemen list l */

/*** Operasi-Operasi Lain ***/
List inverseList(List l)
{
    if (isEmpty(l))
    {
        return l;
    }
    else
    {
        return konsb(inverseList(tail(l)), head(l));
    }
}
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void splitPosNeg(List l, List *l1, List *l2)
{
    if (isEmpty(l))
    {
        // BASIS
        *l1 = NULL;
        *l2 = NULL;
    }
    else
    {
        // REKURENS
        // if (head(l) >= 0) {
        //     *l1 = konsb(*l1, head(l));
        // } else {
        //     *l2 = konsb(*l2, head(l));
        // }
        // splitPosNeg(tail(l), l1, l2);
        splitPosNeg(tail(l), l1, l2);
        if (head(l) >= 0)
        {
            *l1 = konso(*l1, head(l));
        }
        else
        {
            *l2 = konso(*l2, head(l));
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */

void splitOnX(List l, ElType x, List *l1, List *l2)
{
    if (isEmpty(l))
    {
        // BASIS
        *l1 = NULL;
        *l2 = NULL;
    }
    else
    {
        // REKURENS
        splitOnX(tail(l), x, l1, l2);
        if (head(l) < x)
        {
            *l1 = konso(*l1, head(l));
        }
        else
        {
            *l2 = konso(*l2, head(l));
        }
    }
}
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */

int compareList(List l1, List l2)
{
    if (length(l1) == length(l2))
    {
        if (head(l1) == head(l2))
        {
            if (isOneElmt(l1) && isOneElmt(l2))
            {
                return 0;
            }
            int a = compareList(tail(l1), tail(l2));
            return a;
        }
        else if (head(l1) < head(l2))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else if (length(l1) < length(l2))
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
/* Menghasilkan: -1 jika l1 < l2, 0 jika l1 = l2, dan 1 jika l1 > l2 */
/* Jika l[i] adalah elemen l pada urutan ke-i dan |l| adalah panjang l: */
/* l1 = l2: |l1| = |l2| dan untuk semua i, l1[i] = l2[i] */
/* l1 < l2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari l1 dan l2, l1[i]<l2[i] atau: Jika pada semua elemen pada
urutan i yang sama, l1[i]=l2[i], namun |l1|<|l2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* l1>l2: kebalikan dari l1<l2 */

boolean isAllExist(List l1, List l2)
{
    if (isEmpty(l1))
    {
        return false;
    }
    else if (isOneElmt(l1))
    {
        return isMember(l2, head(l1));
    }
    else
    {
        return isMember(l2, head(l1)) && isAllExist(tail(l1), l2);
    }
}
/* Menghasilkan true jika semua elemen dalam l1 terdapat dalam l2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika l1 kosong, maka hasilnya false. */

List CreateList(List l, int panjangbaris)
{
    if (panjangbaris == 0)
    {
        return NULL;
    }
    else
    {
        int element;
        panjangbaris--;
        scanf("%d", &element);
        // printf("%d\n", element);
        return konso(CreateList(l, panjangbaris), element);
    }
}

void splitOnIdx(List l, int idx, List *l1, List *l2)
{
    if (isEmpty(l))
    {
        // BASIS
        *l1 = NULL;
        *l2 = NULL;
    }
    else if (idx == 0)
    {
        *l1 = NULL;
        *l2 = copy(l);
    }
    else
    {
        // REKURENS
        idx--;
        splitOnIdx(tail(l), idx, l1, l2);
        *l1 = konso(*l1, head(l));
    }
}

List reversePartisi(List l, int jumlahpartisi, int panjangpartisi)
{
    if (isEmpty(l))
    {
        return l;
    }
    else if (jumlahpartisi == 1)
    {
        return inverseList(l);
    }
    else
    {
        if (panjangpartisi > length(l))
        {
            return inverseList(l);
        }
        else
        {
            jumlahpartisi--;
            List l1, l2;
            splitOnIdx(l, panjangpartisi, &l1, &l2);
            l1 = inverseList(l1);
            // printf("l1:\n");
            // displayList(l1);
            return concat(l1, reversePartisi(l2, jumlahpartisi, panjangpartisi));
        }
    }
}

void newdisplayList(List l)
{
    if (isEmpty(l))
    {
    }
    else if (isOneElmt(l))
    {
        printf("%d\n", head(l));
    }
    else
    {

        printf("%d ", head(l));
        newdisplayList(tail(l));
    }
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

int main()
{
    int panjangbaris, panjangpartisi;
    scanf("%d %d", &panjangbaris, &panjangpartisi);

    List l;
    l = CreateList(l, panjangbaris);
    // displayList(l);
    // printf("inverse:\n");
    // l = inverseList(l);
    // displayList(l);
    // List l1, l2;
    // splitOnX(l, 3, &l1, &l2);
    // printf("list 1: \n");
    // displayList(l1);
    // printf("list 2:\n");
    // displayList(l2);
    if (panjangpartisi != 0)
    {
        int jumlahpartisi = panjangbaris / panjangpartisi;
        if (panjangbaris % panjangpartisi != 0)
        {
            jumlahpartisi++;
        }
        // printf("jml : %d\n", jumlahpartisi);
        List hasil = reversePartisi(l, jumlahpartisi, panjangpartisi);

        // printf("hasil:\n");
        newdisplayList(hasil);
        List a;
        displayList(a);
        a = konso(a, 1);
        displayList(a);
        printf("\na\n");
        a = konsb(a, 2);
        displayList(a);
        printf("\nb\n");
        int max = maxList(a);
        printf("3");
        int min = minList(a);
        printf("4");
        int sum = sumList(a);
        printf("5");
        float avg = averageList(a);
        printf("6");
        List inv = inverseList(a);
        printf("max %d min %d sum %d avg %f\n", max, min, sum, avg);
        displayList(inv);
    }
}
