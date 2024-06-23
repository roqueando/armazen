#pragma once
#include <map>
#include <optional>
#include <vector>

namespace drain
{
  class Node
  {
    public:
      static const int MAX_CHILD;
      std::string value;
      std::map<std::string, std::optional<Node>> children;

      Node(std::string value);

      static std::optional<Node> new_possible(std::string value);
      void add_child(std::vector<std::string> tokens, std::string log_entry);

      // This function is to help see the tree
      friend std::ostream& operator<<(std::ostream& out, Node& data);
  };
}
