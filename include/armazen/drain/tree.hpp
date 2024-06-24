#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <string>
#include "node.hpp"

namespace drain
{
  class Tree
  {
    public:
      std::unique_ptr<Node> root;
      int depth;
      
      Tree(int depth);
      void add_log(std::string log_entry);
  };

  std::vector<std::string> tokenize(std::string log_entry, int depth);
}
