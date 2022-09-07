pangkat :: Int -> Int -> Int
pangkat a b
    | b == 0 = 1
    | otherwise = a * pangkat a (b-1)