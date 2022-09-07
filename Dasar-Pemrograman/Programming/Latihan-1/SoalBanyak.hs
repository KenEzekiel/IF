isEmpty :: [a] -> Bool
isEmpty = null
konso :: a -> [a] -> [a]
konso x l = x : l
isAllGanjil :: Integral a => [a] -> Bool
isAllGanjil l
    | isEmpty l = True
    | head l `mod` 2 /= 0 = True && isAllGanjil (tail l)
    | otherwise = error "invalid parameter"

getSmallest :: Ord a => [a] -> a
getSmallest l
    | isEmpty small = head l
    | otherwise = getSmallest (tail l)
    where small = [x | x <- l, x < head l]

delElement :: Int -> [Int] -> [Int]
delElement x l
    | isEmpty l = []
    | head l == x = delElement x (tail l)
    | otherwise = head l `konso` delElement x (tail l)