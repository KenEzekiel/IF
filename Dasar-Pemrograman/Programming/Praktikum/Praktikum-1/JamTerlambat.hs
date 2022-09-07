module JamTerlambat where

-- DEFINISI DAN SPESIFIKASI
jamTerlambat :: Int -> Int -> Int -> (Int, Int, Int, Bool, Int)
{-jamTerlambat merupakan fungsi yang menerima input jam menit detik dan memberikan output sebuah tuple
yang 3 digit pertamanya berisikan selisih waktu input dengan jam mulai konser, digit selanjutnya adalah
value boolean untuk terlambat atau tidaknya Yukirin, dan digit terakhirnya merepresentasikan tingkat kekecewaan penonton-}

jamTerlambat j m d =
    let total = j * 3600 + m * 60 + d
        diff = abs (total - (8 * 3600 + 30 * 60))
        jd = if diff >= 3600 then diff `div` 3600 else 0
        sisa1 = if jd > 0 then diff - jd*3600 else diff
        md = if sisa1 >= 60 then sisa1 `div` 60 else 0
        sisa2 = if md > 0 then sisa1 - md*60 else sisa1
        telat
          | (j > 8) = True
          | (j == 8) && (m > 30) = True
          | (j == 8) && (m == 30) && (d > 0) = True
          | otherwise = False
        poin = if telat then jd * 3600 * 10 + md * 60 * 10 + sisa2 * 10 else 0
    in (jd, md, sisa2, telat, poin)

  
