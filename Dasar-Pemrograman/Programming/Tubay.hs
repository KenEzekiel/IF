makeUnique :: [Char] -> String
makeUnique lc
    | null li = ""
    | not (head li `elem'` tail li) = makeUnique (reverse (tail li)) ++ [head li]
    | otherwise = makeUnique (reverse (tail li))
    where li = reverse lc

-- "Ini adalah String" -> ['I','n','i',' ','a']
{-x `elem` list

abc = [a..z]
I `elem` abc-}

elem' :: Eq a => a -> [a] -> Bool
elem' a li
    | null li = False
    | a == head li = True 
    | otherwise = elem' a (tail li)

sort :: [Int] -> [Int]
sort [] = []
sort li =
    let 
        small = sort [a | a <- tail li, a <= head li]
        big = sort [a | a <- tail li, a > head li]
    in small ++ [head li] ++ big

gabungList :: [Int] -> [Int] -> [Int]
gabungList l1 l2 =
    let l3 = l1 ++ l2
    in sort l3