module Week1 where

import Prelude hiding (gcd)

--Recursao sobre inteiros

next :: Int -> Int
next n
    |n `mod` 2 == 0 = n `div` 2
    |otherwise = 3*n + 1


steps :: Int -> Int
steps x
    |x == 1 = 1
    |otherwise = steps (next x) + 1


stepsCounter :: Int -> (Int, Int)
stepsCounter x
    |x == 1 = (1 , 1)
    |otherwise = (return, tSteps + 1)
        where
            tSteps = steps (next x) 
            return = 1

stepsList :: Int -> ([Int], Int)
stepsList x
    |x == 1 = ([1], 1)
    |otherwise = (y : ysValues, totalSteps + 1)
        where
            y = next x
            (ysValues, totalSteps) = stepsList y


gcd :: Int -> Int -> Int
gcd a 0 = a
gcd a b = gcd b (a `mod` b)

gcdCounter :: Int -> Int -> (Int, Int)
gcdCounter a b 
    |b == 0 = (a , 1)
    |otherwise = (value, totalSteps)
        where
            value = gcd a b
            totalSteps = countSteps a b
                where
                    countSteps a b
                        |b == 0 = 0
                        |otherwise = 1 + countSteps b (a `mod` b)






-- Metodo de Newton

average :: Double -> Double -> Double
average x y = xy / 2
    where
        xy = x + y

goodEnough :: Double -> Double -> Bool
goodEnough guess x
    |good < 0.001 = True
    |otherwise = False
        where
            good = abs (guess^2 - x)

improve :: Double -> Double -> Double
improve guess x = average guess (x / guess)


sqrtIter :: Double -> Double -> Double
sqrtIter guess x
    |goodEnough guess x = guess
    |otherwise = sqrtIter (improve guess x) x


goodEnoughCubic :: Double -> Double -> Bool
goodEnoughCubic guess x
    |goodc < 0.0001 = True
    |otherwise = False
        where
            goodc = abs (guess^3 - x)

improveCubic :: Double -> Double -> Double
improveCubic guess x = xGuess / 3
    where
        xGuess = (x / guess^2) - 2 * guess


cubicIter :: Double -> Double -> Double
cubicIter guess x
    |goodEnoughCubic guess x = guess
    |otherwise = cubicIter (improveCubic guess x) x




--List Comprehensions 


sumSquare :: Int -> Int
sumSquare n = sum [x^2 | x <- [1..n]]

grid :: Int -> Int -> [(Int, Int)]
grid m n = [(x, y) | x <- [0..m], y <- [0..n]]

scalarProduct :: [Int] -> [Int] -> Int
scalarProduct xs ys = sum [x * y | (x, y) <- zip xs ys]


            






