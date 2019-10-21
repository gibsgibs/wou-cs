{-
    Gabriel Brehm
    CS360
    Haskell Lab Part 1
-}

import Data.List
import Data.Char
import Data.Ord
import System.IO


--Problem 1
squareRoot x = x**0.5

--Problem 2
asciiPrevious :: Char -> Char
asciiPrevious x = chr (ord x - 1)

--Problem 3
verifyEven :: Int -> Bool
verifyEven x =
        if (3*x + 1) `mod` 2 == 0 then True
        else False
        
--Problem 4
gaussianProduct x = product([1,3..x])

--Problem 5
largestInList :: [Int] -> Int
largestInList x = maximum (tail(init x))

--Problem 6
constructList :: [Int]
constructList = 6:19:41:(-3):[]
        

--Problem 7
firstXEvens :: Int -> [Int]
firstXEvens x = take x [ y | y <- [0..], y `mod` 2 == 0]

--Problem 8
oddsDivisible3and7 :: Int -> [Int]
oddsDivisible3and7 x = [ x | x <- [0..x], x `mod` 3 == 0, x `mod` 7 == 0, x `mod` 2 /= 0]

--Problem 9
oddsDivisible9 :: Int -> [Int]
oddsDivisible9 x = [ x | x <- [100..x], x `mod` 2 /= 0, x `mod` 9 == 0]

--Problem 10
countNegs :: [Int] -> Int
countNegs x = length (filter (<0) x)

--Problem 11
hexMaps :: [(Int,Char)]
hexMaps = zip [1..15] (['1'..'9'] ++ ['A'..'F'])

--Problem 12
makeList :: Int -> [[Int]]
makeList x = 
        if x <= 0 then [] 
        else makeList(x-1) ++ [[1..x]]

--Problem 13
sanitize :: String -> String
sanitize x = concat [if c == ' ' then "%20" else [c] | c <- x]

--Problem 14
{-
a)  (*) :: Num a => a -> a -> a
    Valid inputs: Int, Integer, Float
    
b)  sqrt :: Floating => a -> a -> a
    Valid inputs: Complex Float, Complex Double, Float, Double
    
c)  min :: Ord a => a -> a -> a
    Valid inputs: Complex Float, Complex Double, Rational
    
d)  div :: Integral a => a -> a -> a
    Valid inputs: Int, Integer, Ratio Int, Ratio Integer
    
e)  (>) :: Ord a => a -> a -> Bool
    Valid inputs: Double, Int, Complex Float
-}

--Problem 15
getSuit :: Int -> String
getSuit x =
        if x == 0 then "Heart"
        else if x == 1 then "Diamond"
        else if x == 2 then "Spade"
        else if x == 3 then "Club"
        else "Invalid Input"

--Problem 16
dotProduct :: (Double,Double,Double) -> (Double,Double,Double) -> Double
dotProduct (a1, b1, c1) (a2, b2, c2) = (a1 * a2) + (b1 * b2) + (c1 * c2)
        
--Problem 17
reverseFirstThree :: [a] -> [a]
reverseFirstThree x =
        if length x > 0 then reverse(take 3 x) ++ drop 3 x
        else []

--Problem 18
feelsLike :: Double -> String
feelsLike x 
        | x < -45.3 = "Cold as Hell."
        | x == -45.3 = "Frostbite central!"
        | x < 32.0 && x > -45.3 = "Below freezing."
        | x < 55.0 && x >= 32.0 = "Kinda cold, I guess."
        | x < 75.5 && x >= 55.0 = "Pretty nice."
        | x < 90.0 && x >= 75.5 = "Getting kind of warm."
        | otherwise = "Hot as Hell."

--Problem 19
feelsLike2 :: Double -> (Double, String)
feelsLike2 x
        | fTemp < -45.3 = (fTemp, "Cold as Hell.")
        | fTemp == -45.3 = (fTemp, "Frostbite central!")
        | fTemp < 32.0 && fTemp > -45.3 = (fTemp, "Below freezing.")
        | fTemp < 55.0 && fTemp >= 32.0 = (fTemp, "Kinda cold, I guess.")
        | fTemp < 75.5 && fTemp >= 55.0 = (fTemp, "Pretty nice.")
        | fTemp < 90.0 && fTemp >= 75.5 = (fTemp, "Getting kind of warm.")
        | otherwise = (fTemp, "Hot as Hell.")
        where fTemp = (x * (9/5) + 32)

--Problem 20
cylinderToVolume :: [(Double,Double)] -> [Double]
cylinderToVolume x = 
        [volume | (r, h) <- x, let volume = pi * r**2 * h]

main=do
        --problem 1
        putStrLn("")
        putStrLn("-Problem 1-")
        putStrLn("Input: 818281336460929553769504384519009121840452831049")
        putStr("Output: ")
        print(squareRoot 818281336460929553769504384519009121840452831049)
        putStrLn("")
        
        --Problem 2
        putStrLn("-Problem 2-")
        putStrLn("Input: 'A'")
        putStr("Output: ")
        print(asciiPrevious 'A')
        putStrLn("")
        
        --Problem 3
        putStrLn("-Problem 3-")
        putStrLn("Input1: 5")
        putStr("Output1: ")
        print(verifyEven 5)
        putStrLn("Input2: 10")
        putStr("Output2: ")
        print(verifyEven 10)
        putStrLn("Input3: 6541562")
        putStr("Output3: ")
        print(verifyEven 6541562)
        putStrLn("")
        
        --Problem 4
        putStrLn("-Problem 4-")
        putStrLn("Input: 100")
        putStr("Output: ")
        print(gaussianProduct 100)
        putStrLn("")
        
        --Problem 5
        putStrLn("-Problem 5-")
        putStrLn("Input: [99,23,4,2,67,82,49,-40]")
        putStr("Output: ")
        print(largestInList [99,23,4,2,67,82,49,-40])
        putStrLn("")
        
        --Problem 6
        putStrLn("-Problem 6-")
        putStr("Output: ")
        print(constructList)
        putStrLn("")
        
        --Problem 7
        putStrLn("-Problem 7-")
        putStrLn("Input: 27")
        putStr("Output: ")
        print(firstXEvens 27)
        putStrLn("")
        
        --Problem 8
        putStrLn("-Problem 8-")
        putStrLn("Input: 200")
        putStr("Output: ")
        print(oddsDivisible3and7 200)
        putStrLn("")
        
        --Problem 9
        putStrLn("-Problem 9-")
        putStrLn("Input: 200")
        putStr("Output: ")
        print(oddsDivisible9 200)
        putStrLn("")
        
        --Problem 10
        putStrLn("-Problem 10-")
        putStrLn("Input: [(-4),6,7,8,(-14)]")
        putStr("Output: ")
        print(countNegs [(-4),6,7,8,(-14)])
        putStrLn("")
        
        --Problem 11
        putStrLn("-Problem 11-")
        putStr("Output: ")
        print(hexMaps)
        putStrLn("")
       
        --Problem 12
        putStrLn("-Problem 12-")
        putStrLn("Input1: 7")
        putStr("Output1: ")
        print(makeList 7)
        putStrLn("Input2: 0")
        putStr("Output2: ")
        print(makeList 0)
        putStrLn("Input3: -1")
        putStr("Output3: ")
        print(makeList (-1))
        putStrLn("")
        
        --Problem 13
        putStrLn("-Problem 13-")
        putStrLn("Input: \"http://wou.edu/my homepage/I love spaces.html\"")
        putStr("Output: ")
        print(sanitize "http://wou.edu/my homepage/I love spaces.html")
        putStrLn("")
        
        --Problem 15
        putStrLn("-Problem 15-")
        putStrLn("Input1: 0")
        putStr("Output1: ")
        print(getSuit 0)
        putStrLn("Input2: 1")
        putStr("Output2: ")
        print(getSuit 1)
        putStrLn("Input3: 2")
        putStr("Output3: ")
        print(getSuit 2)
        putStrLn("Input4: 3")
        putStr("Output4: ")
        print(getSuit 3)
        putStrLn("Input5: 77")
        putStr("Output5: ")
        print(getSuit 77)
        putStrLn("")
        
        --Problem 16
        putStrLn("-Problem 16-")
        putStrLn("Input: (1,2,3.0) (4.0,5,6)")
        putStr("Output: ")
        print(dotProduct (1,2,3.0) (4.0,5,6))
        putStrLn("")
        
        --Problem 17
        putStrLn("-Problem 17-")
        putStrLn("Input1: [1]")
        putStr("Output1: ")
        print(reverseFirstThree [1])
        putStrLn("Input2: [1,2]")
        putStr("Output2: ")
        print(reverseFirstThree [1,2])
        putStrLn("Input3: [1,2,3]")
        putStr("Output3: ")
        print(reverseFirstThree [1,2,3])
        putStrLn("Input4: [1,2,3,4]")
        putStr("Output4: ")
        print(reverseFirstThree [1,2,3,4])
        putStrLn("")
        
        --Problem 18
        putStrLn("-Problem 18-")
        putStrLn("Input1: -200")
        putStr("Output1: ")
        print(feelsLike (-200))
        putStrLn("Input2: 200")
        putStr("Output2: ")
        print(feelsLike 200)
        putStrLn("Input3: -45.3")
        putStr("Output3: ")
        print(feelsLike (-45.3))
        putStrLn("Input4: 79")
        putStr("Output4: ")
        print(feelsLike 79)
        putStrLn("")
        
        --Problem 19
        putStrLn("-Problem 19-")
        putStrLn("Input1: -200")
        putStr("Output1: ")
        print(feelsLike2 (-200))
        putStrLn("Input2: -0.1")
        putStr("Output2: ")
        print(feelsLike2 (-0.1))
        putStrLn("Input3: -42.9444444444444444444444444445")
        putStr("Output3: ")
        print(feelsLike2 (-42.9444444444444444444444444445))
        putStrLn("Input4: 100")
        putStr("Output4: ")
        print(feelsLike2 100)
        putStrLn("")
        
        --Problem 20
        putStrLn("-Problem 20-")
        putStrLn("Input: [(2,5.3),(4.2,9),(1,1),(100.394)]")
        putStr("Output: ")
        print(cylinderToVolume [(2,5.3),(4.2,9),(1,1),(100.3,94)])


        
