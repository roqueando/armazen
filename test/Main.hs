module Main (main) where

import Test.Hspec
import Test.Data.Log.Parser (parserTests)

main :: IO ()
main = hspec $ do
  parserTests
