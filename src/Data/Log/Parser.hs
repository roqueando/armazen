module Data.Log.Parser where

import Data.Log.Types (Layer (..))

lengthLayer :: String -> Layer
lengthLayer e = Length (calculatedLength e)
  where
    calculatedLength = length . words

