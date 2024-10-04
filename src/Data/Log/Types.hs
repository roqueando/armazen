module Data.Log.Types (Layer (..)) where

data Layer =  Length Int | Token String
  deriving (Show, Eq)
  -- fn :: Num a => a

  {--
     Length 5
        |
        |
  Token "Temperature"
        |
        |
  Token "*"
        |
        |
  Token "exceeds"
        |
        |
    LogGroup [Parameter]
    --> Parameter { event = "Temperature * exceeds", params = [Param { position = 0, value = "(43C)" }] }
    --}
  {--
     Length 5
        |
        |
  TokenData { token = "Temperature", param = NotParam }
        |
        |
  TokenData { token = "*", param = Param "(43C)" }
        |
        |
  TokenData { token = "exceeds", param = NotParam}
    --}

data Param = NotParam | Param String
  deriving (Show, Eq)

data TokenData = TokenData
  {
    token :: String,
    param :: Param
  }
  deriving (Show, Eq)

