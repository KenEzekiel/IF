module ListOfCharacter where
{-Buatlah fungsi inverse yang menerima masukan sebuah list of character, 
misalnya lc, dan menghasilkan list, misalnya lc’, 
yang berisi elemen-elemen lc dengan urutan yang dibalik. 
Jika lc = [e1,e2,...en-1,en] maka lc’ = [en,en-1,...,e2,e1].-}

inverse :: [a] -> [a]
inverse li
    | null li = []
    | otherwise = inverse(tail li) ++ [head li]

{-Buatlah fungsi konkat yang menerima masukan 2 buah list of character, 
misalnya lc1 dan lc2, yang masing-masing mungkin kosong, dan menghasilkan 
list baru yang merupakan penggabungan lc1 dengan lc2 (lc1 di awal).-}
konkat :: [a] -> [a] -> [a]
konkat lc1 lc2 = lc1 ++ lc2