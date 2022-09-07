module KlasifikasiKomputer where

-- DEFINISI DAN SPESIFIKASI
klasifikasi :: (Eq a, Ord a, Num a) => a -> a -> a -> a
{-klasifikasi adalah sebuah fungsi yang menerima input c g h yang berarti level
cpu, gpu, dan hard disk dan mengembalikan klasifikasi tingkat PC tersebut-}

klasifikasi c g h
    | (c < 2) || (g < 2) || (h < 2) = 1
    | (c < 5) || (g < 5) = 2
    | (c <= 7) && (g <= 7) && (h <= 7) = 3
    | (c <= 7) || (g <= 7) || (h <= 7) = 4
    | (c > 7) || (g > 7) || (h > 7) = 5
    | otherwise = error "invalid parameter"