module Exercise2 where

exclusiveOr :: Bool -> Bool -> Bool
exclusiveOr p q
    | p == q = False
    |otherwise = True

existsPositive :: [Int] -> Bool
existsPositive [] = False
existsPositive (x : xs)
    | x > 0 = True
    | otherwise = False

