-- DEFINISI DAN SPESIFIKASI
sumRange :: (Ord a, Num a) => (a, a) -> a
{-sumRange adalah fungsi yang menerima input range dan mengembalikan output
sum jumlah seluruhnya-}

sumRange (a, b)
    | a == b = b
    | b > a = b + sumRange(a, b-1)
    | otherwise = error "Invalid Parameter"