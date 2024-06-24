#include <iostream>
#include <gtest/gtest.h>
#include <armazen/drain/tree.hpp>

TEST(InsertTest, ShouldInsertNodeInTheTree)
{
  std::unique_ptr<drain::Tree> tree = std::make_unique<drain::Tree>(8);
  std::string log{"Temperature (43C) exceeds"};
  tree->add_log(log);

  EXPECT_EQ(tree->root->children["3"].value().value, "3");

  /*
  EXPECT_EQ(tree->root->children["3"]
      .value()
      .children["Temperature"]
      .value()
      .value, "Temperature");
  EXPECT_EQ(tree->root->children[2].value, "exceeds");
  */
}
