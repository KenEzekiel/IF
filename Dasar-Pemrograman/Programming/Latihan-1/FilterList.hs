
{-DEFINISI DAN SPESIFIKASI-}
{-filterList adalah sebuah fungsi yang menerima input suatu list dan suatu fungsi yang merupakan
sebuah kondisi yang akan diaplikasikan pada list dan mengeluarkan output sebuah list yang pass kondisi yang
diberikan oleh fungsi tersebut-}
filterList :: [Int] -> (Int -> Bool) -> [Int]
isEmpty :: [a] -> Bool

{-REALISASI-}
isEmpty li = null li

filterList li f
    | isEmpty li = []
    | f (head li) = head li : filterList (tail li) f
    | otherwise = filterList (tail li) f

isKabisat x
    | x `mod` 400 == 0 = True
    | x `mod` 100 == 0 = False
    | x `mod` 4 == 0 = True
    | otherwise = False

{-APLIKASI-}

-- filterList [-1,1,2,3,4,5] (\x -> x > 0)
-- filterList [-1,-2,-3,4,5] (\x -> x < 0)
-- filterList [1990,2004,3000,4000,2022] (\x -> x `mod` 4 == 0 && x `mod` 100 /= 0 || x `mod` 400 == 0)