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
indexOf _ [] = -1
indexOf x (y : ys)

