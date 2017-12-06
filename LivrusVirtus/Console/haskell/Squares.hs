--
-- written in Haskell 1.4 (Hugs 1.4 for Windows)
-- by Michael Neumann
--

module Main (main) where

main = putStr (square [1..10])

square :: [Int] -> String
square []    = "\n"
square (h:t) = show (h*h) ++ " " ++ square t



