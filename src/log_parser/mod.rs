pub enum Layer {
    Length(u8),
    Token(TokenData)
}

pub struct TokenData {
    pub token: &'static str,
    pub param: &'static str
}
