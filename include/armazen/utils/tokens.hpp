#pragma once
#include <vector>

namespace utils
{
  std::vector<std::string> remount_without_symbols(std::vector<std::string> tokens);
  bool is_unique_symbol(std::string token);
}
