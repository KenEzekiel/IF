module DeretAritmatika where

{-DEFINISI DAN SPESIFIKASI-}
deretAritmatika :: Int -> Int -> Int -> Float
{-fungsi deretAritmatika yang menerima masukkan 3 nilai integer, 
yaitu n, a, dan b. Parameter a merupakan suku pertama dari suatu barisan aritmatika yang memiliki beda b. -}

deretAritmatika n a b = fromIntegral (n * (2*a + (n-1) * b)) / fromIntegral 2
