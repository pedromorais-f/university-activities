

import Prelude hiding (takeWhile, all, concatMap)


takeWhile :: (a -> Bool) -> [a] -> [a]
takeWhile _ []  = []
takeWhile p (x : xs)
    | p x       = x : takeWhile p xs
    | otherwise = []


takeWhileFoldr :: (a -> Bool) -> [a] -> [a]
takeWhileFoldr f xs = foldr step [] xs
    where
        step x ac
            |f x = x : ac
            |otherwise = []


all :: (a -> Bool) -> [a] -> Bool
all _ [] = True
all f (x : xs)
    |f x = True && all f xs
    |otherwise = False

allFoldr :: (a -> Bool) -> [a] -> Bool
allFoldr f xs = foldr step True xs
    where
        step x ac
            |f x = ac
            |otherwise = False


concatMap :: (a -> [b]) -> [a] -> [b]
concatMap _ [] = []
concatMap f (x : xs) = f x ++ concatMap f xs

concatMapFoldr :: (a -> [b]) -> [a] -> [b]
concatMapFoldr f xs = foldr step [] xs
    where
        step x ac = f x ++ ac