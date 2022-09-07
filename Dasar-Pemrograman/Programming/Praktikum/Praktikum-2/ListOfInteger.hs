module ListOfInteger where
{-Buatlah fungsi elmtKeN yang menerima 
masukan sebuah list of integer, misalnya l,
 dan sebuah integer, misalnya n, 
 dan menghasilkan elemen ke-n dari list of integer l
 . Diasumsikan 0 < n <= banyaknya elemen l dan list l tidak kosong 
 (minimum terdiri atas 1 elemen).-}


elmtKeN :: (Num t, Ord t) => [a] -> t -> a
elmtKeN li n 
    | n == 1 = head li
    | n > 1 = elmtKeN (tail li) (n-1)
    | otherwise = error "Invalid Parameter"