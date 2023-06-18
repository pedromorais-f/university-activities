

bools :: [Bool]
bools = [True, False, False, True]

nums :: [[Int]]
nums = [[1, 2], [3, 4, 5,  6,]]

add :: Int -> Int -> Int -> Int
add x y z = x + y + z

copy :: a -> (a, a)
copy x = (x , x)

apply :: (a -> b) -> a -> b
apply function x = y

swap  :: (a,b) -> (b,a)
swap (x ,y) = (y, x)