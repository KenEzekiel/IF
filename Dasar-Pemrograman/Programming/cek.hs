
{-DEFINISI DAN SPESIFIKASI-}
fDeretTujuh :: Float -> Float
{- Fungsi fDeretTujuh menerima masukan sebuah integer m lebih besar dari nol (m > 0). Fungsi fDeretTujuh menghasilkan bilangan integer yang menyatakan elemen ke-m pada pola bilangan deret segitujuh. -}
{-REALISASI-}
fDeretTujuh m 
| m == 1 = 1
| otherwise = (m/2)*(5*m-3) + fDeretTujuh (m-1)
