{-DEFINISI DAN SPESIFIKASI-}
{-fungsi offsetList adalah sebuah fungsi yang menerima f sebagai fungsi awal yang diimplementasikan kepada a untuk suku pertama,
fungsi g untuk increment, a sebagai suku utama yang diimplementasikan f, dan b sebagai suku akhir-}
offsetList :: (Float -> Float) -> (Float -> Float) -> Float -> Float -> [Float]

{-REALISASI-}
offsetList f g a b
    | a > b = []
    | otherwise = suku : offsetList f g (g a) b
    where suku = f a
{-
*Main> offsetList (\x -> x) (\x -> x + 1) 1 5
[1,2,3,4,5]
*Main> offsetList (\x -> x + 1) (\x -> x + 2) 5 10
[6,8,10]
*Main> offsetList (\x -> x) (\x -> x + 2) 1.2 7.1    
[1.2,3.2,5.2]
*Main> offsetList (\x -> if x < 0 then -999.0 else x + 3.2) (\x -> x + 0.5) (-1.0) 1.0
[-999.0,-999.0,3.2,3.7,4.2]
*Main> offsetList (\x -> x**2) (\x -> x+1) 1.0 9.0
[1.0,4.0,9.0,16.0,25.0,36.0,49.0,64.0,81.0]
-}

isSmall :: Ord a => [a] -> [a]
isSmall li
    | null (tail li) = []
    | head li >= last li = isSmall (init li) ++ [last li]
    | otherwise = isSmall (init li)

isBig :: Ord a => [a] -> [a]
isBig li
    | null (tail li) = []
    | head li < last li = isBig (init li) ++ [last li]
    | otherwise = isBig (init li)
sortirKecil [] = []
sortirKecil li =
    let
        kecil = sortirKecil (isSmall li)
        besar = sortirKecil (isBig li)
    in kecil ++ [head li] ++ besar

sortSmall :: Ord a => [a] -> [a]
sortSmall li
    | null li = []
    | head li <= head (tail li) = head li : sortSmall (tail li)
    | otherwise = sortSmall (tail li ++ [head li])