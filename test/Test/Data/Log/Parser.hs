module Test.Data.Log.Parser where

import Test.Hspec
import Data.Log.Parser (lengthLayer)
import Data.Log.Types (Layer (..))

parserTests :: SpecWith ()
parserTests = describe "when testing parser" $ do
  it "should split by whitespace and return a layer" $ do
    let entry = "[2024-09-28 22:02:37] Temperature (43C) exceeds"
    let expected = lengthLayer entry
    expected `shouldBe` (Length 5)

  it "should return the wild card" $ do
    let entry = "[2024-09-28 22:02:37] Temperature (43C) exceeds"
    let expected = lengthLayer entry
    expected `shouldBe` (Length 5)

