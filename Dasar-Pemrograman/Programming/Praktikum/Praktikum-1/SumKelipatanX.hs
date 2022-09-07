module SumKelipatanX where

-- DEFINISI DAN SPESIFIKASI
sumKelipatanX :: Integral p => p -> p -> p -> p
{-sumKelipatanX adalah fungsi yang menerima masukan dua buah integer positif 
(integer > 0), misalnya m dan n, serta sebuah integer positif lain, 
yaitu x, dan menghasilkan jumlah total bilangan kelipatan x di antara m dan n
(m dan n termasuk) dengan menggunakan ekspresi rekursif.
Bilangan y disebut kelipatan bilangan x, jika y habis dibagi dengan x.-}

-- REALISASI

sumKelipatanX m n x
    | m > n = 0
    | (n `mod` x) == 0 = n + sumKelipatanX m (n-x) x
    | otherwise = sumKelipatanX m (n-1) x