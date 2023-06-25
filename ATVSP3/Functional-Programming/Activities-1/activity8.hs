

data Vec3 = Vec3 Int Int Int


instance Eq Vec3 where
    (Vec3 x1 y1 z1) == (Vec3 x2 y2 z2) =
        x1 == x2 && y1 == y2 && z1 == z2
    type1 /= type2 = not (type1 == type2)



data Person
  = Person {
      name :: String
    , age  :: Int
    }


instance Eq Person where
    (Person xs _) == (Person ys _) = 
        xs == ys
    type1 /= type2 = not (type1 == type2)

instance Show Person where
    show (Person xs a) = "Nome: " ++ xs
