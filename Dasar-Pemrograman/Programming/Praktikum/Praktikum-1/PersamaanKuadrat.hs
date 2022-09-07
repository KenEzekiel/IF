module PersamaanKuadrat where
{-Buatlah definisi, spesifikasi, dan realisasi fungsi persamaanKuadrat 
yang menerima 3 buah bilangan integer (a,b,c) dan sebuah nilai integer x, 
menghasilkan nilai persamaan kuadrat yang dibentuk oleh ketiga bilangan 
tersebut untuk nilai x yang diberikan dengan rumus: ax^2 + bx + c-}

-- persamaanKuadrat
-- DEFINISI DAN SPESIFIKASI
persamaanKuadrat :: Num a => a -> a -> a -> a -> a
{-persamaanKuadrat adalah sebuah fungsi yang menghasilkan nilai dari persamaan kuadrat
 yang diambil dari nilai integer a, b, dan c dan nilai x tertentu-}

-- REALISASI
persamaanKuadrat a b c x = (a * x * x) + (b * x) + c