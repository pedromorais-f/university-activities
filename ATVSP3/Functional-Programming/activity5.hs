import Data.Char


capitalize :: String -> String
capitalize = map toUpper

divisors :: Int -> [Int]
divisors n = [x | x <- [1..n], n `mod` x == 0]

isPrime :: Int -> Bool
isPrime n
    | divisors n == [1, n] = True
    | otherwise = False
    

withoutPrimes :: [Int] -> [Int]
withoutPrimes =  filter (not.isPrime)