{-Salinlah program Pangkat2 dalam Bahasa Haskell di bawah ini dan submitlah sebagai hasil praktikum dengan file bernama Pangkat2.hs. Jangan lupa untuk mengetesnya terlebih dahulu di compiler lokal. 
-}

module Pangkat2 where
-- Pangkat2 - pangkat2(x) 
-- Definisi dan Spesifikasi 
pangkat2 :: Int -> Int 
      -- pangkat2(x) menghitung pangkat dua dari x, 
      -- sebuah bilangan integer 
-- Realisasi
pangkat2 x = x * x 
-- Contoh aplikasi
-- pangkat2 2