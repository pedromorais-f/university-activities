module Activityt2 where

import Parser
import Data.Type.Coercion (sym)
import Parser (greedy)


type Fuel = Int
type Distance = Int
type Position = (Int, Int)

data Robot
    = Robot {
       energy :: Fuel,         -- actual energy
       distance :: Distance,   -- distance travelled
      current :: Position     -- current position
    } deriving (Eq, Ord)

example :: Robot
example = Robot {
             energy = 10,
             distance = 5,
             current = (0,0)
           }

data Instr
     = North      -- walk north
     | South      -- walk south
     | East       -- walk east
     | West       -- walk west
     | Collect    -- collect material
     | Recharge   -- stay and recharge
     deriving (Eq, Ord)


data Program
     = Program {
        limit :: Position, -- extreme right map position
        init  :: Position, -- initial position of the robot
        instrs :: [Instr]  -- the program
    } deriving (Eq, Ord, Show)


instance Show Robot where
    show (Robot energy distance current) = "Energy: " ++ show energy ++ "\n" ++ "Distance: " ++ show distance ++ "\n" ++ "tx: " ++ show (fst current) ++ "\n" ++ "ty: " ++ show (snd current) ++ "\n"


instance Show Instr where
    show North = show "North"
    show South = show "South"
    show East = show "East"
    show West = show "West"
    show Collect = show "Collecting"
    show Recharge = show "Recharging"


parserProgram :: Parser Char Program
parserProgram = Program <$> positionParser <*> positionParser <*> parserInstr


positionParser :: Parser Char Position
positionParser = f <$> symbol '[' <*> natural <*> symbol ',' <*> natural <*> symbol ']'
    where
        f _ x _ y _ = (x, y)

parserInstr :: Parser Char [Instr]
parserInstr = greedy (n <|> s <|> e <|> w <|> c <|> r)
    where
        n = const North <$> symbol 'N' 
        s = const South <$> symbol 'S' 
        e = const East <$> symbol 'E' 
        w = const West <$> symbol 'W' 
        c = const Collect <$> symbol 'C' 
        r = const Recharge <$> symbol 'R' 


runRobot :: [Instr] -> Robot -> Robot
runRobot = undefined




