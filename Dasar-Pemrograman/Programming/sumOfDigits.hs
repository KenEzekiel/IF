-- DEFINISI DAN SPESIFIKASI
sumOfDigits :: Int -> Int
{-sumOfDigits adalah fungsi yang menerima suatu input a dan mengembalikan output a1 + a2 + a3 + .. dimana a = a1a2a3..-}

-- REALISASI
sumOfDigits 0 = 0
sumOfDigits a 
    | a > 0 = sumOfDigits (a `div` 10) + a `mod` 10
    | otherwise = sumOfDigitsPosNeg a

sumOfDigitsPosNeg n = sumOfDigits ((-n) `div` 10) + (-n) `mod` 10