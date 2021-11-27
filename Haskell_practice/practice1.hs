import Data.List
import Data.Char
import System.IO


fun:: Integer -> Integer -> Bool
fun x y
    | x>y = True 
    | otherwise = False

charToint :: Char -> Int
charToint x = ord x - ord '0'

doadd :: Int -> Int -> Int 
doadd x y = x + y

domul :: (Int -> Int -> Int) -> Int -> Int -> Int
domul a x y = a x y
     
dotup :: (Int,(Int,Int)) -> Int -> Int
dotup (x,(y,w)) z = x + y + z + w 

funt::String -> String
isdig :: Char -> Bool 
isdig c = (ord c) > 9
upper :: Char -> Char 
upper x = if (ord x) >= 97 then chr ((ord x) - 32) else x
-- upper x = if (ord x <=9) then 
-- skipint :: String -> String 
-- skipint s = [if (ord x) > 9 then x else '' |x <- s]
funt s = [upper x | x <- s,isdig x, ord x > 9]
main = do
    print (funt "Nir123bhay")

-- ghc listinhaskell.hs -o lh.out ;./lh.out