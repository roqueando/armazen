module Test.Data.Log.Parser where

import Test.Hspec
import Data.Log.Parser (split)

parserTests :: SpecWith ()
parserTests = describe "when testing parser" $ do
  it "should split by whitespace" $ do
    let entry = "[2024-09-28 22:02:37] Temperature (43C) exceeds"
    let expected = split entry
    (length expected) `shouldBe` 5
