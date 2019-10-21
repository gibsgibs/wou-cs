import Data.List
import Data.Char
import Data.Ord
import System.IO
import Assn2b

--Problem 1
gcdMine :: Integral a => a -> a -> a
gcdMine x y =
        if y == 0 then x
        else gcdMine y z
        where z = x `mod` y
        
gcdCheck :: Integral a => a -> a -> (a,a,String)
gcdCheck x y = (myAnswer, correctAnswer, comment)
        where myAnswer = gcdMine x y
              correctAnswer = gcd x y
              comment = 
                    if myAnswer == correctAnswer then "Matches"
                    else "Dose not Match"

--Problem 2
fibonacci :: Int -> Int
fibonacci x =
        if x == 0 then 0
        else if x == 1 || x == 2 then 1
        else fibonacci(x - 1) + fibonacci (x - 2)
        
fibSeq :: Int -> [Int]
fibSeq x = [fibonacci y | y <- [0..x]]

--Problem 3
count :: (Eq a, Num b) => a -> [a] -> b
count x s = 
        if length s == 0 then 0
        else if x == head s then 1 + count x z
        else count x z
        where z = drop 1 s
                
--Helper Function for Problem 4
findElement :: Char -> String -> Int
findElement x s =
        if length s == 0 then 404
        else if head s == x then 0
        else 1 + findElement x (tail s)
        
--Problem 4
sanitize :: String -> String
sanitize x =
        if elem ' ' x == False then x
        else take (findElement ' ' x) x ++ "%20" ++ sanitize (drop (findElement ' ' x + 1) x)
        
--Problem 5
multBy10 :: Num a => a -> a
multBy10 x = x * 10

multListBy10 :: Num a => [a] -> [a]
multListBy10 s = map multBy10 s

--Problem 6
increment1 :: Num a => a -> a
increment1 x = x + 1

incrementList1 :: Num a => [a] -> [a]
incrementList1 s = map increment1 s

increment2 :: Char -> Char
increment2 x = chr(ord x + 1)

incrementList2 :: [Char] -> [Char]
incrementList2 s = map increment2 s 

--Problem 7
divisibleBy42 :: Integral a => a -> Bool
divisibleBy42 x =
        if x `mod` 42 == 0 then True
        else False

containsDivisibleBy42 :: Integral a => [a] -> Bool
containsDivisibleBy42 s = 
        if length s == 0 then False
        else any divisibleBy42 s

--Problem 8
powersOf10 :: Integral a => [a] -> [a]
powersOf10 s = zipWith (^) [10,10..] s 
        
--Problem 9
stringStripper :: String -> String
stringStripper x = reverse y
        where y = dropWhile (== ' ') (reverse x)
        
--Problem 10
isEven :: Integral a => a -> Bool
isEven x = 
        if x `mod` 2 == 0 then True
        else False

evenNumbers :: Integral a => [a] -> Bool
evenNumbers x = all isEven x

--Problem 11
addNot :: String -> String
addNot x = "Not " ++ x
        
addNotToList :: [String] -> [String]
addNotToList x = map addNot x
        
--Problem 12
reverseString :: String -> String
reverseString x = reverse x

reverseListString :: [String] -> [String]
reverseListString x = map reverseString x

--Problem 13
addNumbers = \x -> \y -> x + y

--Problem 14
times4 = \x -> x * 4

--Problem 15
secondElement = \x -> x !! 1

--Problem 16
roundSquare = \x -> round (sqrt x)

--Problem 17
splitSentence = \x -> words x

--Problem 18
triangles = map (\x -> (fst x, snd x, sqrt(fst x^2 + snd x^2)))

main=do
        --Problem 1
        putStrLn "-Problem 1-"
        putStrLn "Input: 18, 42"
        putStr "Output: "
        print(gcdMine 18 42)
        putStrLn "gcdCheck... check"
        print(gcdCheck 111 259)
        print(gcdCheck 2945 123042)
        print(gcdCheck (2*5*7)(7*23))
        putStrLn""
        
        --Problem 2
        putStrLn "-Problem 2-"
        putStrLn "Input: 20"
        putStr "Output: "
        print(fibSeq 20)
        putStrLn ""
        
        --Problem 3
        putStrLn "-Problem 3-"
        putStrLn "Input1: 7 [1,7,6,2,7,7,9]"
        putStr "Output1: "
        print(count 7 [1,7,6,2,7,7,9])
        putStrLn "Input2: 'w' \"western oregon wolves\""
        putStr "Output2: "
        print(count 'w' "western oregon wolves")
        putStrLn ""
        
        --Problem 4
        putStrLn "-Problem 4-"
        putStrLn "Input1: \"http://wou.edu/my homepage/I love spaces.html\""
        putStr "Output1: "
        print(sanitize "http://wou.edu/my homepage/I love spaces.html")
        putStrLn ""
        
        --Problem 5
        putStrLn "-Problem 5-"
        putStrLn "Input: [1,2,3,4,5,6,7,8,9]"
        putStr "Output: "
        print(multListBy10 [1..9])
        putStrLn ""
        
        --Problem 6
        putStrLn "-Problem 6-"
        putStrLn "First Function"
        putStrLn "Input: [1,2,3,4,5,6,7,8,9]"
        putStr "Output: "
        print(incrementList1 [1..9])
        putStrLn "Second Function"
        putStrLn "Input: \"Haskell is fun.\""
        putStr "Output: "
        print(incrementList2 "Haskell is fun.")
        putStrLn ""
        
        --Problem 7
        putStrLn "-Problem 7-"
        putStrLn "Input1: [12,15,87,968,54,23,5875,665,25,2]"
        putStr "Output1: "
        print(containsDivisibleBy42 [12,15,87,968,54,23,5875,665,25,2])
        putStrLn "Input1: [987,85,53,336,2125,21,5151,84,646,64]"
        putStr "Output1: "
        print(containsDivisibleBy42 [987,85,53,336,2125,21,5151,84,646,64])
        putStrLn ""
        
        --Problem 8
        putStrLn "-Problem 8-"
        putStrLn "Input1: [1,3,5,7,9]"
        putStr "Output1: "
        print(powersOf10 [1,3,5,7,9])
        putStrLn ""
        
        --Problem 9
        putStrLn "-Problem 9-"
        putStrLn "Input: \"That is pretty neat         \""
        putStr "Output: "
        print(stringStripper "That is pretty neat         ")
        putStrLn ""
        
        --Problem 10
        putStrLn "-Problem 10-"
        putStrLn "Input: [2,2,4,6]"
        putStr "Output: "
        print(evenNumbers [2,2,4,6])
        putStrLn ""
        
        --Problem 11
        putStrLn "-Problem 11-"
        putStrLn "Input: [\"my chair\",\"my problem\"]"
        putStr "Output: "
        print(addNotToList ["my chair", "my problem"])
        putStrLn ""
        
        --Problem 12
        putStrLn "-Problem 12-"
        putStrLn "Input: [\"This\",\"is\",\"a\",\"sentence\"]"
        putStr "Output: "
        print(reverseListString ["This","is","a","sentence"])
        putStrLn ""
        
        --Problem 13
        putStrLn "-Problem 13-"
        putStrLn "Input: 8 9"
        putStr "Output: "
        print(addNumbers 8 9)
        putStrLn ""
        
        
        --Problem 14
        putStrLn "-Problem 14-"
        putStrLn "Input: 8"
        putStr "Output: "
        print(times4 8)
        putStrLn ""
        
        
        --Problem 15
        putStrLn "-Problem 15-"
        putStrLn "Input: [1,4,6,7,8,9]"
        putStr "Output: "
        print(secondElement [1,4,6,7,8,9])
        putStrLn ""
        
        --Problem 16
        putStrLn "-Problem 16-"
        putStrLn "Input: 17"
        putStr "Output: "
        print(roundSquare 17)
        putStrLn ""
        
        --Problem 17
        putStrLn "-Problem 17-"
        putStrLn "Input: \"This is a sentence written in the usual way\""
        putStr "Output: "
        print(splitSentence "This is a sentence written in the usual way")
        putStrLn ""
        
        --Problem 18
        putStrLn "-Problem 18-"
        putStrLn "Input: [(3,4),(5,16),(9.4,2)]"
        putStr "Output: "
        print(triangles [(3,4),(5,16),(9.4,2)])
        putStrLn ""
        
        --Part02_Problem 1
        putStrLn "-Part02_Problem 1-"
        putStrLn "First Expression: foldl 6 [5,3,8]"
        putStrLn "Equivilent to: ((6*5)*3)*8"
        putStrLn "Second Expression: foldr 6 [5,3,8]"
        putStrLn "Equivilent to: 5*(3*(8*6))"
        putStrLn "Note: In this case we are dealing with a comutative operator "
        putStrLn "over the real numbers, namely multiplication. Additionally, "
        putStrLn "the real numbers are closed under multiplication. Hence, the two "
        putStrLn "expressions have the same result. This is not the case for "
        putStrLn "operators such as division or subtraction."
        putStrLn ""
        
        --Part02_Problem 2
        putStrLn "-Part02_Problem 2-"
        putStrLn "Input: [9,8,7,6,5,4,3,2,1,0]"
        putStr "Output: "
        print(myLength [9,8,7,6,5,4,3,2,1,0])
        putStrLn ""

        --Part02_Problem 3.1
        putStrLn "-Part02_Problem 3.1-"
        putStrLn "Input: [1,2,3,4,5]"
        putStr "Output: "
        print(convertInttoStringLeft [1,2,3,4,5])
        putStrLn ""
        
        --Part02_Problem 3.2
        putStrLn "-Part02_Problem 3.2-"
        putStrLn "Input: [1,2,3,4,5]"
        putStr "Output: "
        print(convertInttoStringRight [1,2,3,4,5])
        putStrLn ""
        
        --Part02_Problem 4.1
        putStrLn "-Part02_Problem 4.1"
        putStrLn "Original Function: length(filter(<20)[1..100])"
        putStr "Output: "
        print(length(filter(<20)[1..100]))
        putStrLn "Rewritten Function: length.filter (<20) $[1..100]"
        putStr "Output: "
        print(length.filter (<20) $[1..100])
        putStrLn ""
        
        --Part02_Problem 4.2
        putStrLn "-Part02_Problem 4.2"
        putStrLn "Original Function: take 10 (cycle (filter (>5) (map (*2) [1..10])))"
        putStr "Output: "
        print(take 10 (cycle (filter (>5) (map (*2) [1..10]))))
        putStrLn "Rewritten Function: take 10.cycle.filter (>5).map (*2) $[1..10]"
        putStr "Output: "
        print(take 10.cycle.filter (>5).map (*2) $[1..10])
        putStrLn "" 

        putStr (reverseString "bob ")