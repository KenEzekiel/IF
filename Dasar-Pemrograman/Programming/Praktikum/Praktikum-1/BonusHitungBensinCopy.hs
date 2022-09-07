module HitungBensin where

-- DEFINISI DAN SPESIFIKASI
bensin :: Integral a => a -> [a]
hitungLength :: Foldable t1 => (t2 -> t1 a) -> t2 -> Int
hitungBensin :: Int -> Int -> Int
{-hitungBensin adalah sebuah fungsi yang menerima 2 input a dan b dimana a adalah lokasi awal dan b adalah lokasi akhir
dan mengeluarkan output sesuai unit bensin yang dikeluarkan. 
Genap X/2
Ganjil (3X + 1)
-}
hitungBensin a b 
    | b < a = 0
    | otherwise = hitungLength bensin b + hitungBensin a (b-1)
    
bensin a 
    | a == 1 = []
    | even a = (a `div` 2) : bensin (a `div` 2) 
    | odd a = (3*a + 1) : bensin (3*a+1)
    | otherwise = error "Invalid Parameter"

hitungLength f x = length (f x)

