{-DEFINISI DAN SPESIFIKASI-}
{-fungsi sumInteger adalah sebuah fungsi yang menerima input dua buat integer dan fungsi
dan mengeluarkan sebuah output integer, dimana integer tersebut adalah penjumlahan dari semua elemen
dalam list yang memenuhi fungsi, dimana list adalah [m..n]-}
sumInteger :: Int -> Int -> (Int -> Bool) -> Int

{-REALISASI-}
sumInteger m n f
    | m == n = 0
    | f m = m + sumInteger (m+1) n f
    | otherwise = sumInteger (m+1) n f

{-APLIKASI-}
-- sumInteger 1 100 (\x -> 100 `mod` x == 0)
-- 117
-- sumInteger 1 100 (\x -> x `mod` 2 == 0 && x `mod` 10 == 0 || x `mod` 2 == 1 && x `mod` 5 == 0)
-- 950
-- sumInteger 25 25 (\x -> x < 10)
-- 0