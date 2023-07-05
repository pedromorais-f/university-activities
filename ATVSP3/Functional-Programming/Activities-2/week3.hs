import Data.List (transpose)
-- 1 2 3   1 2 3              
-- 4 5 6   4 5 6   

--Manipulacao de matrizes

type Matrix = [[Float]]

example :: Matrix
example = [[1.0, 2.0],[4.0, 5.0]]

example1 :: Matrix
example1 = [[1.0, 2.0]]

invalidExample :: Matrix
invalidExample = [[1.0, 2.0, 3.0]]

uniform :: [Float] -> Bool
uniform [] = True
uniform (x : []) = True
uniform (x : y : xs)
    |x == y = True && uniform xs
    |otherwise = False



valid :: Matrix -> Bool
valid xs = uniform (foldr step [] xs)
    where
        step x ac = fromIntegral(length x) : ac


dimension :: Matrix -> (Int, Int)
dimension [] = (0, 0)
dimension xs
    |valid xs = (a, b)
    |otherwise = error "Invalid Matrix"
        where
            a = length xs
            b = head (map length xs)


square :: Matrix -> Bool
square [] = False
square xs = verify (dimension xs)
    where
        verify (a, b)
            |a == b = True
            |otherwise = False


idMatriz :: Int -> Matrix
idMatriz n = [[fromIntegral(fromEnum (x == y)) | y <- [1..n]] | x <- [1..n]]

zipWithZip :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWithZip f xs ys = [f x y | (x, y) <- zip xs ys]

zipWithMap :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWithMap f xs ys = map (\(x, y) -> f x y) (zip xs ys)

zipWithUncurry :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWithUncurry f xs ys = map (uncurry f) (zip xs ys)


nullMatrix :: (Int, Int) -> Matrix
nullMatrix (a, b) = [[fromIntegral(0) | y <- [1..a]] | x <- [1..b]]


addRow :: [Float] -> [Float] -> [Float]
addRow xs ys = map (\(x, y) -> x + y) (zip xs ys)

sumMatrix :: Matrix -> Matrix -> Matrix
sumMatrix [] [] = []
sumMatrix (x : xs) (y : ys) = zipWithMap (+) x y : sumMatrix xs ys
sumMatrix _ _ = error "Invalid Sizes"


innerProduct :: [Float] -> [Float] -> Float
innerProduct [] _ = 0
innerProduct _ [] = 0
innerProduct (x : xs) (y : ys) 
    |length (x : xs) == length (y : ys) = x*y + innerProduct xs ys
    |otherwise = error "Invalid Sizes"

multMatrix :: Matrix -> Matrix -> Matrix
multMatrix xs ys = [[innerProduct x y] | x <- xs , y <- transpose ys]






