/* File: wordmachine.c */
/* Definisi Word Machine: Model Akuisisi Versi I */
/* NAMA : Kenneth Ezekiel Suprantoni */
/* NIM : 13521089 */

#include "wordmachine.h"

/* State Mesin Word */
boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    /*KAMUS LOKAL*/
    int i = 0;

    /*ALGORITMA*/
    // Pemrosesan elemen pertama
    currentWord.TabWord[i] = currentChar;
    ADV();
    i++;
    // Pemrosesan elemen selanjutnya sampai bertemu MARK atau BLANK
    while ((currentChar != MARK) && (currentChar != BLANK))
    {
        if (i < NMax)
        {
            currentWord.TabWord[i] = currentChar;
            ADV();
            i++;
        }
        else
        {
            ADV();
        }
    }
    currentWord.Length = i;
}

void LowerCase()
{
    /* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
    /* F.S. currentword menjadi lowercase di setiap karakternya */
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    for (i = 0; i < currentWord.Length; i++)
    {
        if ((currentWord.TabWord[i] >= 65) && (currentWord.TabWord[i] <= 90))
        {
            currentWord.TabWord[i] = currentWord.TabWord[i] + 32;
        }
    }
}