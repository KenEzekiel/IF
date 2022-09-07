module OffsetList where

{-Tuliskan definisi, spesifikasi, dan realisasi fungsi offsetList yang menerima masukan sebuah list of integer yang melakukan “offset” atau perubahan nilai terhadap elemen list sesuai dengan aturan tertentu (yang ditentukan oleh sebuah fungsi offset) dan menghasilkan list baru dengan elemen hasil offset.

Contoh: 
Dengan fungsi offset plus2, akan menghasilkan list baru dengan nilai setiap elemen yang sudah bertambah 2
Dengan fungsi offset minus1, akan menghasilkan list baru dengan nilai setiap elemen yang sudah berkurang 1
Dengan fungsi offset offKond, akan menghasilkan list baru dengan nilai setiap elemen yang diubah sesuai ketentuan range tertentu-}

offsetList :: [Int] -> (Int -> Int) -> [Int]
offsetList l offset = map offset l