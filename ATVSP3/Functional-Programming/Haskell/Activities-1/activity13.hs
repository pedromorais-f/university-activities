module Activity where

import Parser

idParser :: Parser Char [String]
idParser = listOf identifier (symbol ',')



