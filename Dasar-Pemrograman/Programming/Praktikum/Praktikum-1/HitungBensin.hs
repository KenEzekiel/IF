module HitungBensin where

-- DEFINISI DAN SPESIFIKASI
bensin :: Integral a => a -> [a]
hitungBensinDemo :: Int -> Int
hitungBensin :: Int -> Int -> Int
{-hitungBensin adalah sebuah fungsi yang menerima 2 input a dan b dimana a adalah lokasi awal dan b adalah lokasi akhir
dan mengeluarkan output sesuai unit bensin yang dikeluarkan. 
Genap X/2
Ganjil (3X + 1)
-}

bensin a 
    | a == 1 = []
    | even a = (a `div` 2) : bensin (a `div` 2) 
    | odd a = (3*a + 1) : bensin (3*a+1)
    | otherwise = error "Invalid Parameter"

hitungBensinDemo x = length (bensin x)

hitungBensin a b 
    | b < a = 0
    | otherwise = hitungBensinDemo b + hitungBensin a (b-1)