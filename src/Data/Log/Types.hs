module Data.Log.Types (Layer (..)) where

data Layer = Length Int | Token String
  deriving (Show, Eq)

data Param = NonNumerical | Wildcard String
  deriving (Show, Eq)

data TokenData = TokenData
  {
    token :: String,
    param :: Param
  }
  deriving (Show, Eq)

