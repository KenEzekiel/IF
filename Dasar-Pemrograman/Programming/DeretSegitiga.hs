-- DEFINISI DAN SPESIFIKASI
deretSegitiga :: (Eq p, Num p) => p -> p
{-fungsi Deret Segitiga adalah fungsi yang menerima input n dan mengeluarkan
output deret segitiga sampai bilangan ke n-}

-- REALISASI
deretSegitiga 1 = 1
deretSegitiga n = n + deretSegitiga (n-1)