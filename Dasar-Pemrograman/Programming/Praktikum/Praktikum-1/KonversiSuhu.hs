module KonversiSuhu where
{-Buatlah sebuah fungsi konversiSuhu (definisi, spesifikasi, dan realisasi) 
yang digunakan untuk mengkonversi suhu dari satu satuan Celcius ke satuan 
suhu yang lain, yaitu Fahrenheit, Reamur, atau Kelvin. Berikut adalah rumus
 untuk melakukan konversi jika suhu dalam derajat Celcius adalah C: -}

-- konversiSuhu
-- DEFINISI DAN SPESIFIKASI
konversiSuhu :: (Fractional a) => a -> Char -> a
{-konversiSuhu adalah fungsi yang menerima sebuah bilangan float x dalam celcius
dan sebuah char y yang melambangkan tujuan unit temperatur dan mengubah Celcius ke unit tujuan sesuai rumusnya-}
konversiSuhu x y 
    | y == 'R'= (4/5) * x
    | y == 'F' = (9/5 * x) + 32
    | y == 'K' = x + 273.15
    | otherwise = error "Invalid parameter"