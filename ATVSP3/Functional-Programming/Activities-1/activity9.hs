


inRange :: Int -> Int -> [Int] -> [Int]
inRange a b xs = [x | x <- xs , x >= a && x <= b]

inRangeProperty :: Int -> Int -> [Int] -> Bool
inRangeProperty a b = foldr step True
    where
        step x ac
            |x >= a && x <= b = True && ac
            |otherwise = False