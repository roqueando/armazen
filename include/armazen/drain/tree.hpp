#pragma once
#include <iostream>
#include <map>

namespace drain
{
  class Node
  {
    public:
      std::string value;
      std::map<std::string, Node> children;

      Node(std::string value);
  };

  class Tree
  {
    public:
      Node *root;
      int depth;
      
      Tree(int depth);
      void add_log(std::string log_entry);
  };

  std::vector<std::string> tokenize(std::string log_entry);

}
