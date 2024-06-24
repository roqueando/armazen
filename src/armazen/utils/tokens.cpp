#include <iostream>
#include <cstddef>
#include <vector>
#include <regex>
#include <string>

namespace utils
{

  bool is_unique_symbol(std::string token)
  {
    if (token.size() == 1) {
      bool has_hyphen = token.find("-");
      char character = token[0];
      std::string scharacter;
      scharacter.assign(character, character + token.size());

      return has_hyphen || std::regex_search(scharacter, std::regex("[^\\w\\s]"));
    }
    return false;
  }

  std::vector<std::string> remount_without_symbols(std::vector<std::string> tokens)
  {
    std::vector<std::string> new_tokens;
    for (const auto& token : tokens) {
      if (!is_unique_symbol(token)) {
        new_tokens.push_back(token);
      }
    }
    return new_tokens;
  }


}
