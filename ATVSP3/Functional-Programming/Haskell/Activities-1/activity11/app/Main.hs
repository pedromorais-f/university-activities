module Main (main) where


main :: IO ()
main = textStatistics

textStatistics :: IO ()
textStatistics = do
    args <- getLine
    info <- readFile args
    let numberOfWords = countWords info
    let numberOfLines = countLines info
    putStrLn $ "Number of words: " ++ show numberOfWords
    putStrLn $ "Number of lines: " ++ show numberOfLines


countWords :: String -> Int
countWords = length . words

countLines :: String -> Int
countLines = length . lines