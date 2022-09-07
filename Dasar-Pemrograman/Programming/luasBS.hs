-- DEFINISI DAN SPESIFIKASI
luasBS :: Int -> Int
{-fungsi luasBS adalah sebuah fungsi yang menerima input suatu panjang sisi n
dan mengeluarkan output luas persegi tersebut-}

-- REALISASI
luasBS 1 = 1
luasBS n = 2 * n - 1 + luasBS (n-1)