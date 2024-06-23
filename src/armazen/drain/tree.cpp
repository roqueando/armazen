#include <iostream>
#include <vector>
#include <armazen/drain/tree.hpp>
#include <armazen/drain/node.hpp>
#include <ranges>
#include <string_view>

namespace drain
{
  Tree::Tree(int depth) : depth(depth), root(std::make_unique<Node>("root")) {}

  void Tree::add_log(std::string log_entry)
  {
    std::vector<std::string> tokens = tokenize(log_entry, depth);
    std::string length = std::to_string(tokens.size());

    if (root->children.find(length) == root->children.end()) {
      root->children.insert({length, Node::new_possible(length)});
    }

    root->children[length]->add_child(tokens, log_entry);
  }

  std::vector<std::string> tokenize(std::string log_entry, int depth)
  {
    std::string_view delim{" "};
    std::string_view log = (std::string_view)log_entry;

    std::vector<std::string> tokens;
    for(const auto token : std::ranges::views::split(log, delim))
    {
      if (tokens.size() == depth) {
        break;
      }

      tokens.push_back(std::string(std::string_view(token)));
    }

    return tokens;
  }
}
