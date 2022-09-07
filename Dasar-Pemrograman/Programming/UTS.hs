map' :: (t -> a) -> [t] -> [a]
map' _ [] = []
map' f li = f (head li) : map' f (tail li)

isOneElmnt :: [Int] -> Bool
isOneElmnt li = (length li == 1)

isSmall :: [Int] -> [Int]
isSmall li
    | isOneElmnt li = []
    | last li <= head li = last li : isSmall (init li)
    | otherwise = isSmall (init li)

isBig :: [Int] -> [Int]
isBig li
    | isOneElmnt li = []
    | last li > head li = last li : isBig (init li)
    | otherwise = isBig (init li)

sort' :: [Int] -> [Int]
sort' [] = []
sort' li =
    let 
        small = sort' (isSmall li)
        big = sort' (isBig li)
    in small ++ [head li] ++ big

-- salah
{-DEFINISI DAN SPESIFIKASI-}
fDeretTujuh :: Int -> Int
{- Fungsi fDeretTujuh menerima masukan sebuah integer m lebih besar dari nol (m > 0). Fungsi fDeretTujuh menghasilkan bilangan integer yang menyatakan elemen ke-m pada pola bilangan deret segitujuh. -}
{-REALISASI-}
fDeretTujuh m
    | m == 1 = 1
    | m == 2 = 7
    | otherwise = 6 + 5*(m-2) + fDeretTujuh (m-1)

isEmpty = null

isMember x l
    | null l = False
    | head l == x = True
    | otherwise = isMember x (tail l)

aturParkir li n f
    | isEmpty li = ([],0)
    | otherwise = 
        let
            (hasil,x) = aturParkir (tail li) n f
        in
            if isMember (f (head li)) hasil then
                (hasil,x+1)
            else if f (head li) < 0 || f (head li) >= n then
                (hasil,x+1)
            else
                ( (f (head li)) : (hasil) ,x)
