module Assn2b
(
counter,
myLength,
convertInttoStringLeft,
convertInttoStringRight
)where

import Data.Char

--Par02_Problem 1
{-

-}

--Par02_Problem 2
{-
So, foldl requires a two parameter function as its first parameter, 
so I had to use a dummy variable because I could not figure out how 
else to do it. 
-}
counter :: Int -> a -> Int
counter x y = x + 1

myLength :: [a] -> Int
myLength x = foldl (counter) 0 x

--Par02_Problem 3.1
convertInttoStringLeft :: [Int] -> [Char]
convertInttoStringLeft (x:xs) = 
        if myLength (x:xs) == 0 then ""
        else if myLength (x:xs) == 1 then [intToDigit x]
        else foldl (++) [intToDigit x] [convertInttoStringLeft xs]

        
--Par02_Problem 3.2
convertInttoStringRight :: [Int] -> [Char]
convertInttoStringRight (x:xs) = 
        if myLength (x:xs) == 0 then ""
        else if myLength (x:xs) == 1 then [intToDigit x]
        else foldr (++) [intToDigit x] [convertInttoStringRight xs]

