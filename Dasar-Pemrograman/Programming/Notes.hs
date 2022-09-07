
makeUnique :: [Char] -> String
makeUnique lc
    | null li = ""
    | head li `notElem` tail li = makeUnique (reverse (tail li)) ++ [head li]
    | otherwise = makeUnique (reverse (tail li))
    where li = reverse lc


sort' :: Ord a => [a] -> [a]
sort' [] = []
sort' li =
    let small = sort' [a | a <- tail li, a <= head li]
        big = sort' [a | a <- tail li, a > head li]
    in small ++ [head li] ++ big
gabungList :: [Int] -> [Int] -> [Int]
gabungList l1 l2 =
    let l3 = l1 ++ l2
    in sort' l3