data Toy a b =
    Output a b
  | Bell b
  | Done


instance Functor (Toy a) where
    fmap _ Done = Done
    fmap f (Bell y) = Bell (f y)
    fmap f (Output x y) = Output x (f y)

