module ListIndex where
{-uliskan definisi, spesifikasi, dan realisasi dari fungsi listIndex yang menerima masukan:



sebuah list of integer, misalnya l

sebuah fungsi yang menerima masukan sebuah integer dan menghasilkan sebuah char, misal f



Fungsi listIndex akan menghasilkan sebuah list of character yang melambangkan nilai-nilai indeks dari suatu list nilai integer.

Misal fungsi f akan mengembalikan nilai B untuk range nilai [70,80], maka nilai 75 akan secara otomatis diubah menjadi 'B' oleh fungsi f.



Hint: Materi fungsi sebagai parameter dari fungsi / High Order function, Jadi masukan dari fungsi ini adalah 2, L dan F, dimana L adalah sebuah List, dan F adalah sebuah Fungsi. Misalnya pada contoh di bawah ini, F dimasukkan dengan fungsi nilai (tidak usah diimplementasikan), dan L dimasukkan dengan sebuah array. Sehingga, apabila terjadi perubahan skala nilai, hanya perlu membuat implementasi nilai yang baru/bisa dengan fungsi lambda dan memanggil langsung fungsi listIndex tanpa harus mengubah implementasi pada listIndex.
-}

map' :: (t -> a) -> [t] -> [a]
map' _ [] = []
map' f (x:xs) = f x : map' f xs

listIndex :: [Int] -> (Int -> Char) -> [Char]
listIndex l f = map' f l