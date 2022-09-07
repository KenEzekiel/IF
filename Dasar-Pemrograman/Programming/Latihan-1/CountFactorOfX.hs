module CountFactorOfX where

factor :: (Integral a) => a -> [a]
factor n = [a | a <- [1..n], n `mod` a == 0]

countFactorOfX :: Int -> [Int] -> Int
countFactorOfX n [] = 0
countFactorOfX n l
    | head l `elem` factorOfN = 1 + countFactorOfX n (tail l)
    | otherwise = countFactorOfX n (tail l)
    where factorOfN = factor n

delNthElmt :: Int -> [Char] -> [Char]
delNthElmt n l
    | n == 1 = tail l
    | otherwise = head l : delNthElmt (n-1) (tail l)

{-DEFINISI DAN SPESIFIKASI-}
sumIsiList :: [Int] -> Int
{-sumIsiList  menghitung hasil penjumlahan dari seluruh elemen sebuah list of integer l yang tidak kosong -}
{-REALISASI-}
sumIsiList l
    | null l = 0
    | otherwise = head l + sumIsiList (tail l)

{-DEFINISI DAN SPESIFIKASI-}
filterGanjil :: [Int] -> [Int]
{-filterGanjil yang  melakukan filtering terhadap sebuah list of integer li sehingga menghasilkan list dengan elemen yang hanya terdiri atas bilangan ganjil yang muncul di li. ​
Diasumsikan semua elemen li adalah bilangan integer positif atau 0. ​
li mungkin kosong.-}
{-REALISASI-}
filterGanjil li
    | null li = []
    | head li `mod` 2 == 1 = head li : filterGanjil (tail li)
    | otherwise = filterGanjil (tail li)


isEqFront :: Eq a => [a] -> [a] -> Bool
isEqFront t1 t2
    | null t1 = True
    | head t1 == head t2 = True && isEqFront (tail t1) (tail t2)
    | otherwise = False