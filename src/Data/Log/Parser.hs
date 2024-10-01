module Data.Log.Parser where

data Layer a = Root
             | Length a
             | Token a

split :: String -> [String]
split e = words e
