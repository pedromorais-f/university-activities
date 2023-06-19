
import Data.Char

-- Recursao sobre listas

--Exe1

inRange :: Int -> Int -> [Int] -> [Int]
inRange x y zs = [a | a <- zs, a >= x && a <= y]


inRangeRec :: Int -> Int -> [Int] -> [Int]
inRangeRec _ _ [] = []
inRangeRec x y (z : zs)
    |z >= x && z <= y = z : inRangeRec x y zs
    |otherwise = inRangeRec x y zs


propInRange :: Int -> Int -> [Int] -> Bool
propInRange x y zs
    |(inRange x y zs) == (inRangeRec x y zs) = True
    |otherwise = False


--Exe2

countPositivies :: [Int] -> Int
countPositivies xs = length [y | y <- xs, y > 0]

countPositiviesRec :: [Int] -> Int
countPositiviesRec [] = 0
countPositiviesRec (x : xs)
    |x > 0 = 1 + countPositiviesRec xs
    |otherwise = countPositiviesRec xs

propCountPositive :: [Int] -> Bool
propCountPositive xs
    |(countPositivies xs) == (countPositiviesRec xs) = True
    |otherwise = False


--Exe3

toTitleString :: String -> String
toTitleString [] = []
toTitleString (x : xs) = toUpper x : map toLower xs

propToTitleStringCorrect :: String -> Bool
propToTitleStringCorrect xs = verify (toTitleString xs)
    where
        verify [] = False
        verify (x : xs) = isUpper x && all isLower xs


--Exe4

halfEvens :: [Int] -> [Int]
halfEvens xs = [x `div` 2 | x <- xs, even x]


halfEvensRec :: [Int] -> [Int]
halfEvensRec [] = []
halfEvensRec (x : xs)
    |even x = x `div` 2 : halfEvensRec xs
    |otherwise = halfEvensRec xs


propHalfEvens :: [Int] -> Bool
propHalfEvens xs
    |(halfEvens xs) == (halfEvensRec xs) = True
    |otherwise = False


--Funcoes de ordem superior

--Exe1

uppers :: String -> String
uppers xs = map toUpper xs

propUppersCorrect :: String -> Bool
propUppersCorrect xs = verifyS (uppers xs)
    where
        verifyS [] = True
        verifyS (x : xs)
            |isUpper x = True && verifyS xs
            |otherwise = False


--Exe2

centsToReals :: [Int] -> [Float]
centsToReals xs = map toReals xs
    where
        toReals x = (fromIntegral x) / 100

--Exe3

alphas :: String -> String
alphas xs = filter isLetter xs
    where
        isLetter x
            |isLower x = True
            |isUpper x = True
            |otherwise = False


propAlphasCorrect :: String -> Bool
propAlphasCorrect xs = verifyStr (alphas xs)
    where
        verifyStr [] = True
        verifyStr (x : xs)
            |isLower x = True && verifyStr xs
            |isUpper x = True && verifyStr xs
            |otherwise = False

    

