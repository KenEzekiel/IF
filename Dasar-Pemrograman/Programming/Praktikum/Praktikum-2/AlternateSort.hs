module AlternateSort where
{-Diberikan sebuah list, Pak Engi memiliki sebuah algoritma prosedural sebagai berikut.

1. Urutkan list tersebut

2. Bagi list menjadi 2 sama besar, misal l1 dan l2. Jika panjang list ganjil, maka l1 akan memiliki 1 elemen lebih banyak dibanding l2

3. Ambil elemen terkecil dari l1, masukkan ke akhir l3.

4. Ambil elemen terbesar dari l2, masukkan ke akhir l3.

5. Ulangi langkah 3 dan 4 sampai kedua list kosong.



Contohnya, jika list awal adalah [9,10,11,12], maka l3 akan menjadi [9,12,10,11]



Pak Engi telah selesai membuat algoritma prosedural tersebut. Anda, sebagai pemrogram handal, ingin membuat versi fungsional dari kode tersebut. Namun, anda menyadari bahwa langkah prosedural tersebut terlalu kompleks untuk diimplementasikan dalam waktu 2 jam, sehingga anda ingin mencari cara lain untuk mengimplementasikan algoritma tersebut. Buatlah program yang dapat melakukan algoritma tersebut!-}

sortirKecil :: [Int] -> [Int]
sortirKecil [] = []
sortirKecil li =
    let
        kecil = sortirKecil [a | a <- tail li, a <= head li]
        besar = sortirKecil [a | a <- tail li, a > head li]
    in kecil ++ [head li] ++ besar

sortirBesar :: [Int] -> [Int]
sortirBesar [] = []
sortirBesar li =
    let
        kecil = sortirBesar [a | a <- tail li, a <= head li]
        besar = sortirBesar [a | a <- tail li, a > head li]
    in besar ++ [head li] ++ kecil

alternateSort :: [Int] -> [Int]
alternateSort li
    | length kecil == 1 = [head kecil]
    | null kecil = []
    | otherwise = [head kecil] ++ besar ++ alternateSort (init (tail kecil))
    where
        kecil
            | null li = []
            | otherwise = sortirKecil li
        besar 
            | null (tail kecil) = [] 
            | otherwise = [last kecil]
