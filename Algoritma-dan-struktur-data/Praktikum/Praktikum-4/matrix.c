/*Nama: Kenneth Ezekiel S
NIM: 13521089
Pra Praktikum ADT Matrix*/

/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
{
    /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
    /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor *** */
//#define ROW_EFF(M) (M).rowEff
//#define COL_EFF(M) (M).colEff
//#define ELMT(M, i, j) (M).mem[(i)][(j)]

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
{
    /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return (i >= 0) && (i < ROW_CAP) && (j >= 0) && (j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
{
    /* Mengirimkan Index baris terbesar m */
    return (ROW_EFF(m) - 1);
}
IdxType getLastIdxCol(Matrix m)
{
    /* Mengirimkan Index kolom terbesar m */
    return (COL_EFF(m) - 1);
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j)
{
    /* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return (i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m));
}
ElType getElmtDiagonal(Matrix m, IdxType i)
{
    /* Mengirimkan elemen m(i,i) */
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
{
    /* Melakukan assignment mOut <- mIn */
    ROW_EFF(*mOut) = ROW_EFF(mIn);
    COL_EFF(*mOut) = COL_EFF(mIn);

    *mOut = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
{
    /* I.S. isIdxValid(nRow,nCol) */
    /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
    /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10
    */
    /*KAMUS LOKAL*/
    int i, j;
    ElType elm;
    /*ALGORITMA*/
    createMatrix(nRow, nCol, m);

    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &elm);
            ELMT(*m, i, j) = elm;
        }
    }
}
void displayMatrix(Matrix m)
{
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
       dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
    /*KAMUS LOKAL*/
    int i, j;
    /*ALGORITMA*/

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            printf("%d", ELMT(m, i, j));
            if (j != COL_EFF(m) - 1)
            {
                printf(" ");
            }
        }
        if (i != ROW_EFF(m) - 1)
        {
            printf("\n");
        }
    }
    printf("\n");
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
{
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil penjumlahan matriks: m1 + m2 */
    /*KAMUS LOKAL*/
    Matrix m3;
    int i, j;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);

    for (i = 0; i < ROW_EFF(m3); i++)
    {
        for (j = 0; j < COL_EFF(m3); j++)
        {
            ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m3;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    /*KAMUS LOKAL*/
    Matrix m3;
    int i, j;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);

    for (i = 0; i < ROW_EFF(m3); i++)
    {
        for (j = 0; j < COL_EFF(m3); j++)
        {
            ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m3;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
    /* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    /*KAMUS LOKAL*/
    Matrix m3;
    int i, j, k;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);

    for (i = 0; i < ROW_EFF(m3); i++)
    {
        for (j = 0; j < COL_EFF(m3); j++)
        {
            ELMT(m3, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++)
            {
                ELMT(m3, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return m3;
}
Matrix multiplyByConst(Matrix m, ElType x)
{
    /* Mengirim hasil perkalian setiap elemen m dengan x */
    /*KAMUS LOKAL*/
    Matrix m3;
    int i, j;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m), COL_EFF(m), &m3);

    for (i = 0; i < ROW_EFF(m3); i++)
    {
        for (j = 0; j < COL_EFF(m3); j++)
        {
            ELMT(m3, i, j) = ELMT(m, i, j) * x;
        }
    }
    return m3;
}
void pMultiplyByConst(Matrix *m, ElType k)
{
    /* I.S. m terdefinisi, k terdefinisi */
    /* F.S. Mengalikan setiap elemen m dengan k */
    /*KAMUS LOKAL*/
    int i, j;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(*m, i, j) = ELMT(*m, i, j) * k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
{
    /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
    /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
    /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    /*KAMUS LOKAL*/
    int i, j;
    boolean eq = true;
    /*ALGORITMA*/
    i = 0;
    j = 0;
    // Jika ukuran matrix berbeda, maka matrix tidak mungkin sama
    if ((countElmt(m1) != countElmt(m2)))
    {
        eq = false;
    }
    // Skema searching untuk mencari ketidaksamaan
    while ((eq == true) && (i < ROW_EFF(m1)))
    {
        while ((eq == true) && (j < COL_EFF(m1)))
        {
            if (ELMT(m1, i, j) != ELMT(m2, i, j))
            {
                eq = false;
            }
            j++;
        }
        i++;
    }

    return eq;
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
    /* Mengirimkan true jika m1 tidak sama dengan m2 */
    return !isMatrixEqual(m1, m2);
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
    /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    return (ROW_EFF(m1) == ROW_EFF(m2)) && ((COL_EFF(m1) == COL_EFF(m2)));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
{
    /* Mengirimkan banyaknya elemen m */
    return (ROW_EFF(m) * COL_EFF(m)) - (COL_EFF(m) - (getLastIdxCol(m) + 1));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
{
    /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return ROW_EFF(m) == COL_EFF(m);
}
boolean isSymmetric(Matrix m)
{
    /* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
       dan untuk setiap elemen m, m(i,j)=m(j,i) */
    /*KAMUS LOKAL*/
    boolean sym = true;
    int i, j;
    /*ALGORITMA*/
    i = 0;
    j = 0;
    if (isSquare(m) == true)
    {
        while ((i < ROW_EFF(m)) && (sym != false))
        {
            while ((j < COL_EFF(m)) && (sym != false))
            {
                if (ELMT(m, i, j) != ELMT(m, j, i))
                {
                    sym = false;
                }
                j++;
            }
            i++;
        }
    }
    else
    {
        sym = false;
    }

    return sym;
}
boolean isIdentity(Matrix m)
{
    /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
       setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    /*KAMUS LOKAL*/
    boolean id = true;
    int i, j;
    /*ALGORITMA*/
    i = 0;
    j = 0;
    if (isSquare(m) == true)
    {
        while ((i < ROW_EFF(m)) && (id != false))
        {
            while ((j < COL_EFF(m)) && (id != false))
            {
                if (i == j)
                {
                    if (ELMT(m, i, j) != 1)
                    {
                        id = false;
                    }
                }
                else
                {
                    if (ELMT(m, i, j) != 0)
                    {
                        id = false;
                    }
                }
                j++;
            }
            i++;
        }
    }
    else
    {
        id = false;
    }

    return id;
}
boolean isSparse(Matrix m)
{
    /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
       hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    /*KAMUS LOKAL*/
    float max = (ROW_EFF(m) * COL_EFF(m)) * 0.05;
    max = (int)max; // Round down
    int countNotZero = 0;
    int i, j;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                countNotZero++;
            }
        }
    }

    return (countNotZero <= max);
}
Matrix negation(Matrix m)
{
    /* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
    /*KAMUS LOKAL*/
    Matrix m3;
    int i, j;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m), COL_EFF(m), &m3);

    for (i = 0; i < ROW_EFF(m3); i++)
    {
        for (j = 0; j < COL_EFF(m3); j++)
        {
            ELMT(m3, i, j) = ELMT(m, i, j) * (-1);
        }
    }
    return m3;
}
void pNegation(Matrix *m)
{
    /* I.S. m terdefinisi */
    /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    /*KAMUS LOKAL*/
    int i, j;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(*m, i, j) = ELMT(*m, i, j) * (-1);
        }
    }
}

Matrix minor(Matrix m, int row, int col)
{
    /*Prekondisi: isSquare(m), isIdxEff(m, row, col)*/
    /*Return matrix minor, dimana row dan col dihilangkan*/

    /*KAMUS LOKAL*/
    Matrix temp;
    int i, j, x, y;

    /*ALGORITMA*/
    createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &temp);

    x = 0;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        if (i != row)
        {
            y = 0;
            for (j = 0; j < COL_EFF(m); j++)
            {
                if (j != col)
                {
                    ELMT(temp, x, y) = ELMT(m, i, j);
                    y++;
                }
            }
            x++;
        }
    }
    return temp;
}

float determinant(Matrix m)
{
    /* Prekondisi: isSquare(m) */
    /* Menghitung nilai determinan m */
    /*Menggunakan matrix segitiga atas -> rekursi*/
    /*Menggunakan OBE mengurangkan dengan k kali baris lain, sehingga tidak mengubah determinan*/
    /*KAMUS LOKAL*/
    int i, j;
    float det;
    int sign = 1;

    /*ALGORITMA*/
    // Basis
    // Return elemen satu-satunya matriks nya jika matriks berukuran 1x1
    if (ROW_EFF(m) == 1)
    {
        return ELMT(m, 0, 0);
    }
    det = 0;
    // Rekurens
    for (i = 0; i < COL_EFF(m); i++)
    {
        det += sign * ELMT(m, 0, i) * determinant(minor(m, 0, i));
        sign *= (-1);
    }
    return det;
}
Matrix transpose(Matrix m)
{
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    /*KAMUS LOKAL*/
    Matrix mhasil;
    int i, j;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m), COL_EFF(m), &mhasil);

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            ELMT(mhasil, j, i) = ELMT(m, i, j);
        }
    }

    return mhasil;
}
void pTranspose(Matrix *m)
{
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    /*KAMUS LOKAL*/
    Matrix mhasil;
    int i, j;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(*m), COL_EFF(*m), &mhasil);

    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(mhasil, j, i) = ELMT(*m, i, j);
        }
    }

    *m = mhasil;
}