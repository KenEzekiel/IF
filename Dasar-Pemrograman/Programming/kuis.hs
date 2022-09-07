-- Fungsi Menentukan Suku ke-n		sukuKeN (n) 
-- DEFINISI DAN SPESIFIKASI
sukuKeN :: Int -> Int
{-Fungsi sukuKeN adalah suatu fungsi yang menerima input sebuah integer n (n >= 1) dan mengeluarkan output suku ke-n dari barisan 1, -4, 7, -10, 13 .. -}
-- REALISASI
-- Asumsi n selalu n >= 1
sukuKeN n 
    | (n `mod` 2) == 1 = 1 + 3*(n-1)
    | (n `mod` 2) == 0 = (-1) * (1 + 3*(n-1))
    | otherwise = error "Invalid Parameter"



-- Fungsi menghitung THP			thp (p, d)
-- DEFINISI DAN SPESIFIKASI
thp :: Bool -> Int -> Int
{-fungsi thp adalah sebuah fungsi yang menerima input p (boolean) dan d (integer) dan mengembalikan output take home pay atau gaji yang diterima oleh karyawan tersebut-}
-- REALISASI
-- Asumsi 0 <= d <= 30
thp p d 
    | p && d < 15 = 200000 * d
    | p && d >= 20 = 4000000 + 100000 * (d - 20)
    | not p && d >= 20 = 150000 * 20 + 175000 * (d - 20)
    | not p && d < 20 = 150000 * d
    | otherwise = error "Invalid Parameter"
