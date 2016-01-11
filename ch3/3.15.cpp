#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> sv;
  std::string s;
  while (std::cin >> s)
    sv.push_back(s);
  for (const auto & k : sv)
    std::cout << k << " ";
  std::cout << std::endl;

  return 0;
}
