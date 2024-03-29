import Prelude hiding (Word, lines)

type Text = String
type Line = String
type Word = String
type Index = [([Int], Word)]


lines :: Text -> [Line]
lines "" = []
lines ('\n': xs) = lines xs
lines xs = line : lines ys
    where
        (line, ys) = break (== '\n') xs


numberLines :: [Line] -> [(Int, Line)]
numberLines xs = [(a, b) | (a, b) <- zip [1..length xs] xs]


createList :: Int -> [Int]
createList x = x : createList x

numberWords :: (Int, Line) -> [(Int, Word)]
numberWords (x, xs) = [(a , b) |(a, b) <- zip (take (length (words xs)) (createList x)) (words xs)]

numberAll :: [(Int, Line)] -> [(Int, Word)]
numberAll [] = []
numberAll (x : xs) = numberWords x ++ numberAll xs


(.<.) :: (Int, Word) -> (Int, Word) -> Bool
(l1, w1) .<. (l2, w2) = w1 < w2 || (w1 == w2 && l1 < l2)

sortEntries :: [(Int,Word)] -> [(Int, Word)]
sortEntries [] = []
sortEntries (x : xs) = smallers ++ [x] ++ largers
    where
        smallers = sortEntries [(a, b) | (a, b) <- xs , (a, b) .<. x]
        largers = sortEntries [(a, b) | (a, b) <- xs , not ((a, b) .<. x)]


--combine :: [(Int, Word)] -> Index
--combine [] = []










