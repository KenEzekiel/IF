-- DEFINISI DAN SPESIFIKASI
isGanjil :: (Eq t, Num t) => t -> Bool
{-isGanjil adalah fungsi yang menerima suatu input n dan mengembalikan output
apakah bilangan tersebut ganjil atau tidak (boolean)-}

-- REALISASI
isGanjil 0 = False
isGanjil 1 = True
isGanjil n = isGanjil (n-2)