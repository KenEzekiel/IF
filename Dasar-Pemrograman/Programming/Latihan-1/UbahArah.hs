ubahArah :: Int -> Int -> Int
ubahArah s r
    | r == 0 = s
    | r > 0 && s + r >= 360 = (s + r) - 360
    | r > 0 && s + r < 360 = s + r
    | r < 0 && s + 360 + r >= 360 = s + r
    | r < 0 && s + 360 + r < 360 = s + 360 + r
    | otherwise = error "invalid parameter"