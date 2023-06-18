module Activity2 where

xor :: Bool -> Bool -> Bool
xor x y
    |x == y = False
    |otherwise = True

existsPositive :: [Int] -> Bool
existsPositive [] = False
existsPositive (x : xs)
    |x > 0 = True
    |otherwise = existsPositive xs



