module SumOfDigits where

-- DEFINISI DAN SPESIFIKASI
sumOfDigits :: Int -> Int
{-sumOfDigits adalah fungsi yang menerima suatu input a dan mengembalikan output a1 + a2 + a3 + .. dimana a = a1a2a3..-}

-- REALISASI
sumOfDigits 0 = 0
sumOfDigits a = sumOfDigits (a `div` 10) + a `mod` 10