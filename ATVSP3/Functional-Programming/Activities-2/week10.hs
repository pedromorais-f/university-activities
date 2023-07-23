

--Parser functions

newtype Parser s a
     = Parser {
         runParser :: [s] -> [(a,[s])]
       }

infixr 4 <|>

(<|>) :: Parser s a -> Parser s a -> Parser s a
(Parser p) <|> (Parser q)
   = Parser (\ inp -> p inp ++ q inp)

failure :: Parser s a
failure = Parser (\ _ -> [])

succeed :: a -> Parser s a
succeed v = Parser (\ inp -> [(v,inp)])

instance Functor (Parser s) where
   fmap f (Parser p)
      = Parser (\ inp -> [(f x, xs) | (x,xs) <- p inp])

instance Applicative (Parser s) where
   pure = succeed
   (Parser p) <*> (Parser q)
     = Parser (\ inp -> [(f x, xs) | (f, ys) <- p inp
                                   , (x, xs) <- q ys])

first :: Parser s a -> Parser s a
first (Parser p)
   = Parser (\ inp -> let r = p inp
                      in if null r then []
                         else [head r])

many :: Parser s a -> Parser s [a]
many p = ((:) <$> p <*> many p) <|> succeed []

many1 :: Parser s a -> Parser s [a]
many1 p = (:) <$> p <*> many p

greedy :: Parser s a -> Parser s [a]
greedy = first . many

greedy1 :: Parser s a -> Parser s [a]
greedy1 = first . many1


-- Week exercises

data Bit = O | I deriving (Eq, Ord, Show)


data Field
  = Field {
      size :: Int
    , content :: [Bit]
    } deriving (Eq, Ord)


data UDP
  = UDP {
      source :: Field       --- 16 bits
    , destination :: Field  --- 16 bits
    , plength :: Field      --- 16 bits
    , checksum :: Field     --- 16 bits
    , pdata :: [Field]      --- list of 32 bit fields
    } deriving (Eq, Ord)


bitParser :: Parser Char Bit
bitParser = Parser (\inp -> case inp of
                    [] -> []
                    (x : xs) -> [(if x == '1' then I else O, xs)]
                  )


bitList :: Int -> Parser Char [Bit]
bitList n = Parser (\inp -> case n of
                     0 -> [([], inp)]
                     n -> case inp of
                        [] -> []
                        xs -> [(
                           (fst2 $ runParser (greedy bitParser) [x | (x, y) <- zip inp [0..], y < n]), drop n xs)]
      )
      where
         fst2 [(a, b)] = a



fieldParser :: Int -> Parser Char Field
fieldParser n = undefined