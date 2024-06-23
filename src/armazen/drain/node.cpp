#include <iostream>
#include <armazen/drain/node.hpp>
#include <optional>
#include <vector>

namespace drain
{
  const int Node::MAX_CHILD = 100;

  Node::Node(std::string value) : value(value) {}

  std::optional<Node> Node::new_possible(std::string value)
  {
    if (value != "") {
      Node n(value);
      return n;
    }
    return {};
  }

  void Node::add_child(std::vector<std::string> tokens, std::string log_entry)
  {
    if (this->children.size() > MAX_CHILD) {
      return;
    }

    if (tokens.size() == 0) {
      // TODO: add a log group because this is now a leaf node
      return;
    }
    std::string node_path;
  }

  std::ostream& operator<<(std::ostream& out, Node& data)
  {
    out << "Node { " << data.value << " }";
    return out;
  }
}
