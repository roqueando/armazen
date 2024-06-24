#include <iostream>
#include <gtest/gtest.h>
#include <armazen/utils/tokens.hpp>

TEST(RemountWithoutSymbolsTest, ShouldRemountWithoutAnySymbols)
{
  std::vector<std::string> tokens = {"Temperature", "(43C)", "exceeds"};
  tokens = utils::remount_without_symbols(tokens);

  std::vector<std::string> expected_tokens = {"Temperature", "(43C)", "exceeds"};

  EXPECT_EQ(tokens, expected_tokens);
}

TEST(IsUniqueSymbol, ShouldReturnTrueIfUniqueSymbol)
{
  EXPECT_TRUE(utils::is_unique_symbol("-"));
}

TEST(IsUniqueSymbol, ShouldReturnFalseIfNotUniqueSymbol)
{
  EXPECT_FALSE(utils::is_unique_symbol("Temperature"));
}
