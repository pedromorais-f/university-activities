minList :: Ord a => [a] -> a
minList (x : []) = x
minList (x : xs) = menor_num
    where
        num = minList xs
        menor_num
            |x < num = x
            |otherwise = num


andList :: [Bool] -> Bool
andList (x : []) = x
andList (False : _) = False
andList (True : xs) = andList xs


orList :: [Bool] -> Bool
orList (x : []) = x
orList (True : _) = True
orList (False : xs) = orList xs

indexOf :: Int -> [Int] -> Int
indexOf n xs = index n xs 0
    where
        index _ [] _ = -1
        index n (x : xs) ac
            |n == x = ac
            |otherwise = index n xs (ac + 1)

removeAll :: Int -> [Int] -> [Int]
removeAll _ [] = []
removeAll x (y : ys)
    | x == y = [] ++ removeAll x ys
    | otherwise = y : removeAll x ys

