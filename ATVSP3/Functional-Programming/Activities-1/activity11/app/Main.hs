module Main (main) where


main :: IO ()
main = textStatistics

textStatistics :: IO ()
textStatistics = do
    fileRead <- readFile filepath
    let numberOfLines = countLines fileRead
    let numberOfWords = countWords fileRead
    putStrLn ("Number of words:" ++ show numberOfWords)
    putStrLn ("Number of lines:" ++ show numberOfLines)


filepath :: FilePath
filepath = "test.txt"

countLines :: String -> Int
countLines = length . lines

countWords :: String -> Int
countWords = length . words



