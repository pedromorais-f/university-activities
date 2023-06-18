

minList :: Ord a => [a] -> a
minList [] = error "empty list"
minList (x : []) = x
minList (x : xs) = minNumber
    where
        minNumber
            |x < (minList xs) = x
            |otherwise = minList xs


andList :: [Bool] -> Bool
andList [] = error "empty list"
andList (x : []) = x 
andList (False : _) = False
andList (True : xs) = andList xs


orList :: [Bool] -> Bool
orList [] = error "empty list"
orList (x : []) = x
orList (True : _) = True
orList (False : xs) = orList xs


indexOf :: Int -> [Int] -> Int
indexOf _ [] = -1
indexOf x ys = position x ys 0
    where
        position x (y : ys) ac
            |x == y = ac
            |otherwise = position x ys (ac + 1)


removeAll :: Int -> [Int] -> [Int]
removeAll _ [] = error "empty list"
removeAll x ys = [z | z <- ys, x /= z]

    


