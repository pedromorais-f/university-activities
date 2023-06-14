import Prelude hiding (takeWhile, all, concatMap)


takeWhile :: (a -> Bool) -> [a] -> [a]
takeWhile funcao = foldr step base
    where
        base = []
        step x ac
            | funcao x = x : ac
            | otherwise = []


all :: (a -> Bool) -> [a] -> Bool
all _ [] = True
all funcao (x : xs)
    | funcao x = all funcao xs
    | otherwise = False



all1 :: (a -> Bool) -> [a] -> Bool
all1 funcao = foldr step True
    where
        step x ac
            | funcao x = ac
            | otherwise = False


concatMap :: (a -> [b]) -> [a] -> [b]
concatMap _ [] = []
concatMap funcao (x : xs) = funcao x ++ concatMap funcao xs


concatMap1 :: (a -> [b]) -> [a] -> [b]
concatMap1 funcao = foldr step []
    where
        step x ac = funcao x ++ ac 