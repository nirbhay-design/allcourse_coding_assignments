
import Data.List
import Data.Char
import System.IO

p = [2,3,4,5]
q = p ++ [4,5,6,7]
r = 5 : p
s = 2:3:5:6:[]

t = [[1,3],[1,2,3,4]]
m = [1,2,3]:t

len = length p
rev = reverse p
value = p !! 1 -- index

a = 3 `elem` p


la = [2..10]
lb = [2,4..20]
lc = ['A','C'..'X'] -- string but char array

ld = [x * 2 | x<- [1..10]]

le = [if (x<= 3) then x * 3 else x*4 | x <- [2..100] , x * 5 <= 30]

lf = [1,2,3,14]
lg = [3,4,5,6]

lh = zipWith (mod) lf lg

pwr = [x ^ 3 | x <- [1..10]] -- also use x ** 3

ml = [[x * y | y <- [1..10]]|x <- [10..100]]

tup = (1,"random tuples")


file = [1,2,3,4]
tile = ["nirbhay","shara","nishant","chutia"]

mile = zip file tile

addme :: Int -> Int -> Int

addme x y = x + y
    
addTup :: (Int, Int)->(Int, Int) -> (Int, Int)
addTup (x, y) (w, z) = (x +w, z +y) 


main = do
    print la
    print lb
    print (fst tup)
    print (snd tup)
    print (fst (mile !! 2))
    print (addme 2 3)
    print (addTup (2,3) (4,5))
    -- print "enter your name"
    -- name <- getLine 
    -- print ("hi " ++ name)