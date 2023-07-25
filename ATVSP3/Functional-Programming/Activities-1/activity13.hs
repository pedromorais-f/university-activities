module Activity where

import Parser
import Data.Char (isAscii)


data Identifier = ID String deriving Show

parserID :: Parser Char Identifier
parserID = ID <$> greedy (sat isAscii) 

idParser :: Parser Char [Identifier]
idParser = listOf parserID (symbol ',')



