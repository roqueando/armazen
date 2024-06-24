#include <armazen/drain/node.hpp>
#include <armazen/utils/tokens.hpp>
#include <iostream>
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
    std::string token;

    // if only rests one token
    if (tokens.size() == 1) {
      token = tokens[0];
    } else {
      token = std::vector<std::string>(tokens.begin(), tokens.end())[0];
    }

    //tokens = utils::remount_without_symbols(tokens);
  }


  std::ostream& operator<<(std::ostream& out, Node& data)
  {
    out << "Node { " << data.value << " }";
    return out;
  }
}
