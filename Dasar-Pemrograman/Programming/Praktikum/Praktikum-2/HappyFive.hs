module HappyFive where
{-Tuan Vin menyukai angka 5. 
Hanya angka-angka yang berhubungan dengan 5 yang dapat membuat Tuan Vin senang.

Bantulah Tuan Vin untuk membuang setiap angka yang tidak berhubungan dengan 5 
atau kelipatan dari 5 dari sebuah list agar Tuan Vin senang dengan nama fungsi happyFive. 
Angka didalam list hanya bernilai satuan atau puluhan.-}

happyFive :: Integral a => [a] -> [a]
happyFive li
    | null li = []
    | head li `mod` 5 == 0 = head li : happyFive (tail li)
    | head li > 50 && head li < 60 = head li : happyFive (tail li)
    | otherwise = happyFive (tail li)