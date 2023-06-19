
import Data.Char

capitalize :: String -> String
capitalize [] = []
capitalize (x : xs) = toUpper x : capitalize xs

capitalize2 :: String -> String
capitalize2 xs = map toUpper xs


withoutPrimes :: [Int] -> [Int]
withoutPrimes xs = filter (not . isPrime) xs
    where
        isPrime x = (length (primes x)) == 2
        primes x = [y | y <- [1..x], x `mod` y == 0]