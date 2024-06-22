#include <iostream>
#include <vector>
#include <armazen/drain/tree.hpp>
#include <ranges>
#include <string_view>

namespace drain
{
  Node::Node(std::string value) : value(value) {}

  Tree::Tree(int depth) : depth(depth) {}
  void Tree::add_log(std::string log_entry)
  {
    std::vector<std::string> tokens = tokenize(log_entry);
    for (auto &token : tokens) {
      std::cout << token;
    }
  }

  std::vector<std::string> tokenize(std::string log_entry)
  {
    std::string_view delim{" "};
    std::string_view log = (std::string_view)log_entry;

    std::vector<std::string> result;
    for(const auto token : std::views::split(log, delim))
    {
      std::cout << token;
      result.push_back(token);
    }

    return result;
  }
}
