


data Point = Point Float Float


data Shape = 
    Rectangle Point Float Float
   | Circle Point Float
   | Triangle Point Point Point



calDistance :: Point -> Point -> Float
calDistance (Point xa ya) (Point xb yb) = sqrt (x + y)
    where
        x = (xb - xa)^2
        y = (yb - ya)^2 


calculateArea :: Shape -> Float
calculateArea (Rectangle _ base height) = base * height
calculateArea (Circle _ radius) = pi * radius^2
calculateArea (Triangle point1 point2 point3) = bh / 2
    where
        base = calDistance point2 point3
        height = calDistance point2 point1
        bh = base * height

{-

    point1


    point2        point3

-}


data IntTree = ILeaf | INode Int IntTree IntTree

generateTree :: IntTree
generateTree =  INode 32 (INode 15 (INode 14 ILeaf ILeaf) (INode 20 ILeaf ILeaf)) (INode 64 (INode 60 ILeaf ILeaf) (INode 65 ILeaf ILeaf))

numElements :: IntTree -> Int
numElements (INode _ ILeaf ILeaf) = 1
numElements (INode _ l r) = 1 + numElements l + numElements r


numLeafs :: IntTree -> Int
numLeafs ILeaf = 1
numLeafs (INode _ l r) = numLeafs l + numLeafs r


type Name = String
type MiddleName = String
type SendOffer = Bool

data Client = Info{
    name :: Name,
    middleName :: MiddleName,
    sendOffer :: SendOffer
}

deriving instance Show Client

createClientList :: [Client]
createClientList = [
    Info "Neymar" "Junior" True,
    Info "Roberto" "Firmino" False,
    Info "Roger" "Guedes" False,
    Info "Ronaldinho" "Gaucho" True]

offersList :: [Client] -> [Client]
offersList xs = filter verify xs
    where
        verify (Info _ _ True) = True
        verify (Info _ _ False) = False

    