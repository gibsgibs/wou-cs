{-
    Gabriel Brehm
    CS360
    Haskell Lab Part 3
-}

import Data.List
import Data.Char
import Data.Ord
import System.IO

--Problem 1
gallons :: Double -> Double
gallons x = x * 0.264172

usd :: Double -> Double
usd x = x * 0.75

price :: Double -> Double -> Double
price x y = usd x / gallons y

--Problem 2
degreesToRadians :: Double -> Double
degreesToRadians x = x * pi/180

flightDistance :: (Double, Double) -> (Double, Double) -> Double
flightDistance x y = 3963*acos(cos(sig1)*cos(sig2)*cos(lam1-lam2)+sin(sig1)*sin(sig2))
        where sig1 = degreesToRadians(fst x)
              lam1 = degreesToRadians(snd x)
              sig2 = degreesToRadians(fst y)
              lam2 = degreesToRadians(snd y)

--Problem 3
sumOfCubes :: [Int] -> Int
sumOfCubes x = sum [y^3 | y <- x, y `mod` 2 == 1]

--Problem 4.1
notSpace :: Char -> Bool
notSpace x =
        if x == ' ' then False
        else True

removeSpaces :: String -> String
removeSpaces x = filter (notSpace) x

--Problem 4.2
notEven :: Int -> Bool
notEven x =
        if even x == True then False
        else True

filterEvens :: [Int] -> [Int]
filterEvens x = filter (notEven) x

--Problem 4.3
doubleList :: [Int] -> [Int]
doubleList x = map (*2) x

--Problem 4.4
contains55 :: [Int] -> Bool
contains55 x = all (55==) x

--Problem 4.5
allOdd :: [Int] -> Bool
allOdd x = all (odd) x

--Problem 5
allFactors :: Integer -> [Integer]
allFactors x = [y | y <- [2..x-1], x `mod` y == 0]  

isPrime :: Integer -> Bool
isPrime x = 
        if x == 1 then False
        else if allFactors x == [] then True
        else False
        
thousandthPrime :: [Integer] -> [Integer]
thousandthPrime x = take 20 (drop 999 x)

twentyPrimes :: [Integer]
twentyPrimes = thousandthPrime(filter (isPrime) [1..])

--Problem 6       

--My idea for how to solve this problem; works for numbers that are not gigantic 
myFactor :: Integer -> [Integer]
myFactor x = 
        if  isPrime x then [x]
        else [y | y <- [2..z], x `mod` y == 0, isPrime y == True]
        where z = toInteger(round(toRational x / 2))
        
removeDuplecates :: [Integer] -> [Integer]
removeDuplecates x = 
        if length x == 0 then x
        else map head (group x)
        RkL#zn51P
--based on the internet's idea for how to solve this problem; I am pretty salty mine dosen't work
factor :: Integer -> [Integer]
factor n = 
        if n == 1 then []
        else removeDuplecates((prime :) (factor (quot n prime)))
        where prime = head (dropWhile ((/=0).mod n) [2..n])
               
--Problem 7
main=do
        --problem 1
        putStrLn("")
        putStrLn("-Problem 1-")
        putStrLn("Input: 78.4 62.3")
        putStr("Output: ")
        print(price 78.4 62.3)
        putStrLn("")
        
        --problem 2
        putStrLn("")
        putStrLn("-Problem 2-")
        putStrLn("Input: (45, 122), (21, 158)")
        putStr("Output: ")
        print(flightDistance (45, 122) (21, 158))
        putStrLn("")
        
        --problem 3
        putStrLn("")
        putStrLn("-Problem 3-")
        putStrLn("Input: [1000..2000]")
        putStr("Output: ")
        print(sumOfCubes [1000..2000])
        putStrLn("")
        
        --problem 4.1
        putStrLn("")
        putStrLn("-Problem 4.1-")
        putStrLn("Input: \"Haskell is my favorite!\"")
        putStr("Output: ")
        print(removeSpaces "Haskell is my favorite!")
        putStrLn("")
        
        --problem 4.2
        putStrLn("")
        putStrLn("-Problem 4.2-")
        putStrLn("Input: [41,54,67,13,-65,78,423,56,2,2,65,442,23]")
        putStr("Output: ")
        print(filterEvens [41,54,67,13,-65,78,423,56,2,2,65,442,23])
        putStrLn("")
        
        --problem 4.3
        putStrLn("")
        putStrLn("-Problem 4.3-")
        putStrLn("Input: [1..10]")
        putStr("Output: ")
        print(doubleList [1..10])
        putStrLn("")
        
        --problem 4.4
        putStrLn("")
        putStrLn("-Problem 4.4-")
        putStrLn("Input: [11,5,4,66,78,34,98,-64,22]")
        putStr("Output: ")
        print(contains55 [11,5,4,66,78,34,98,-64,22])
        putStrLn("")
        
        --problem 4.5
        putStrLn("")
        putStrLn("-Problem 4.5-")
        putStrLn("Input: [13,7,3,5,67,9,7,5,3,3,9]")
        putStr("Output: ")
        print(allOdd [13,7,3,5,67,9,7,5,3,3,9])
        putStrLn("")
        
        --problem 5
        putStrLn("")
        putStrLn("-Problem 5-")
        putStrLn("Input: 8")
        putStr("Output: ")
        print(twentyPrimes)
        putStrLn("")
        
       
        --problem 6
        putStrLn("")
        putStrLn("-Problem 6-")
        putStrLn("Input1: 175561")
        putStr("Output1: ")
        print(factor 175561)
        putStrLn("Input2: 62451532000")
        putStr("Output2: ")
        print(factor 62451532000)
        putStrLn("")