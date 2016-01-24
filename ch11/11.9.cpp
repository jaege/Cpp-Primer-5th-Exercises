#include <map>
#include <list>
#include <string>
#include <iostream>

int main() {
  std::map<std::string, std::list<int>> words{
      {"ghi", {100, 200}}, {"abc", {1, 3, 5}}, {"def", {2, 4}}};

  for (const auto &w : words) {
    std::cout << w.first << ":";
    for (const auto &l : w.second)
      std::cout << " " << l;
    std::cout << std::endl;
  }

  return 0;
}
