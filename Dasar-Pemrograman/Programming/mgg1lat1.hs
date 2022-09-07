-- Definisi dan Spesifikasi
isJamValid :: Int -> Int -> Int -> Bool
{- IsJamValid(j,m,d) menghasilkan nilai true jika j, m, d menyusun jam 
yang valid. Definisi jam yang valid adalah jika elemen jam (j) 
bernilai antara 0 dan 23, elemen menit (m) bernilai antara 0 dan 59, 
dan elemen detik (d) bernilai antara 0 dan 59. -}
isJamValid j m d
    | (0 < j && j <= 23) && (0 < m && m <= 59) && 0 < d && d <= 59 = True
    | otherwise = False

hitungDetik :: Int -> Int -> Int -> Int
{-Diberikan 3 buah integer j, m, d dengan j adalah integer [0..23], m 
adalah integer [0..59], d adalah integer [0..59], yang artinya adalah
jam (j), menit (m), dan detik (d) pada suatu tanggal tertentu. 
• Hitunglah jumlah detik dari jam tersebut terhitung mulai jam 0:0:0 
pada tanggal ybs-}
hitungDetik j m d = j * 3600 + m * 60 + d

-- DEFINISI DAN SPESIFIKASI
isDateValid :: Int -> Int -> Int -> Bool
{- isDateValid(d,m,y) mengembalikan nilai true jika 
d, m, y membentuk date yang valid. Definisi date yang 
valid adalah jika elemen hari (d) bernilai antara 1 
dan 31, tergantung pada bulan dan apakah tahun kabisat 
atau bukan, elemen bulan (m) bernilai antara 1 dan 12, 
dan elemen tahun (y) bernilai antara 0 dan 99.
Nilai y mewakili tahun 1900 s.d. 1999 -}

isDateValid d m y =
    let yValid = (0 <= y && y <= 99)
        mValid = (0 <= m && m < 12)
        mBesar = [1, 3, 5, 7, 8, 10, 12]
        dValid
            | (m == 2 && y`mod`4 == 0) = (0 < d && d <= 29)
            | (m == 2 && y`mod`4 /= 0) = (0 < d && d < 29)
            | (m `elem` mBesar) = (0 < d && d <= 31)
            | otherwise = (0 < d && d < 31)
    in yValid && mValid && dValid

--sayText :: (Integral a) => a -> String
sayText 1 = "one"
sayText 2 = "two"
sayText 3 = "three"
sayText x = "I don't know"
 {-
head' :: [a] -> a
head' [] = error "Empty List"
head' (x:_) = x
-}

head' :: [a] -> a
head' xs = case xs of
                    [] -> error "Empty List"
                    (x:_) -> x

factorial :: Int -> Int
factorial x
    | x == 1 = 1
    | otherwise = x * factorial (x-1)


max' :: (Ord a) => [a] -> a
max' [] = error "Empty List"
max' [x] = x
max' (x:xs)
    | x > maxTail = x
    | otherwise = maxTail
    where maxTail = max' xs

insert x [] = [x]
insert x (y:ys)
    | x < y = x:(y:ys)
    | otherwise = y:insert x ys

sort' :: (Ord a) => [a] -> [a]
sort' = foldr insert []

jumlahDetik :: Int -> Int -> Int -> Int
jumlahDetik j m d = j * 3600 + m * 60 + d

min3 :: Ord a => a -> a -> a -> a
min3 a b c
    | a < b && a < c = a
    | b < a && b < c = b
    | c < a && c < b = c
    | otherwise = error "No value"

max3 :: Ord a => a -> a -> a -> a
max3 a b c
    | a > b && a > c = a
    | b > a && b > c = b
    | c > a && c > b = c
    | otherwise = error "No value"

nilaiTengah :: Ord a => a -> a -> a -> a
nilaiTengah a b c
    | a `notElem` minmax = a
    | b `notElem` minmax = b
    | c `notElem` minmax = c
    | otherwise = error "No value"
    where minmax = [min3 a b c, max3 a b c]

jadiDollar :: Integral a => a -> a
jadiDollar s = div s 100

mapping :: (Integral a, Show a) => (a, a) -> [Char]
mapping (d, s) = 
    let strd = show d
        strs = show s
    in "Dollar: " ++ strd ++ " Sen: " ++ strs

berapaDollar :: Integral b => b -> b -> b -> b -> (b, b)
berapaDollar q d n p =
    let sen = (q * 25) + (d * 10) + (n * 5) + p
        dollar = div sen 100
        ps = sen - 100*dollar
    in (dollar, ps) 

mapDollar :: (Integral a, Show a) => a -> a -> a -> a -> [Char]
mapDollar a b c d = mapping (berapaDollar a b c d)


