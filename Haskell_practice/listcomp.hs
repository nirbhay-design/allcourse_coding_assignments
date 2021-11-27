import Data.List
import Data.Char
-- import Data.Map
import System.IO

isdig :: Char -> Bool 
isdig c = (ord c - ord '0')>=0 && (ord c - ord '0') <= 9

islower::Char -> Bool
islower c = (ord c - ord 'a')>=0 && (ord c - ord 'a')<=25

toupper::Char -> Char
toupper ch = chr (ord ch - 32)

fun :: String -> String 
fun s = [if (islower y) then toupper y else y |y <- s,not (isdig y)]

-- user defined datatypes
data Mytype = Strong Float | Weak Int 

funct :: Mytype -> String 
funct (Strong x) = if (x > 2.5) then "Strong" else "weak"
funct (Weak x) = if (x < -3) then "weak" else "strong"


function :: [Int] -> Int
function (x:[]) = x
function (x:xs) = x + function xs

f::Int -> String 
f age = "hello" ++ [chr age]

nction:: (Int->String)->Int -> [Int]
nction f a = [ord y | y <- (f a)]

lengthh:: [a] -> Int
lengthh [] = 0
lengthh (x:xs) = 1 + lengthh xs

tpl :: (String,Int,Int) -> Int
tpl (a,b,c) = sum ([ord y | y <-a] ++ [b] ++ [c])

getindex :: [a]->Int -> a
getindex [x] b = x
getindex (x:xs) b
    |b == 0 = x
    |otherwise=getindex xs (b-1)
-- map :: (a->b)->[a]->[b]
mapp :: (a->b) -> [a] -> [b]
mapp f [x] = [f x]
mapp f (x:xs) = (f x):mapp f xs

filterr :: (a->Bool) -> [a] -> [a]
filterr f [] = []
filterr f (x:xs)
    |(f x) == True = x:filterr f xs
    |otherwise= filterr f xs

iseven :: Int -> Bool 
iseven a = a `mod` 2 == 0

zipp :: [a]->[b]->[(a,b)]
zipp [x] [y] = [(x,y)] 
zipp (x:xs) (y:ys) = (x,y):zipp xs ys

zipWithh :: (a->b->c) -> [a] -> [b] -> [c]
zipWithh f [x] [y] = [f x y]
zipWithh f (x:xs) (y:ys) = (f x y):zipWithh f xs ys

rev :: [a] -> [a]
rev [x] = [x]
rev (x:xs) = (rev xs) ++ [x]


insertt :: Int -> [Int] -> [Int]
insertt a ([x]) = if a >= x then [x] ++ [a] else [a] ++ [x]  
insertt a (x:y:xs)
    | a >= x && a <= y = [x] ++ [a] ++ (y:xs)
    | otherwise = [x] ++ (insertt a (y:xs))

main = do
    let value =  filter iseven [1,2,3,4]
    print (2**3)
    print (zip [1,2,3,4] [4,5,6,7])
    print (zipWithh (+) [1,2,3] [4,5,6])
    print (getindex "nirbhay" 20)
    print (rev [1,2,3,4,5])
    let val = [1,2,3,4]
    print (val!!2)
    putStrLn "Nirbhay shamra: "
    myline <- getLine
    putStrLn myline
    -- writeFile "myname.txt" myline
    content <- readFile "myname.txt"
    putStrLn content
    print (insertt 3 [1,2,4,5])

