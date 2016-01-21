#include <vector>
#include <string>
#include <iostream>

int main() {
  std::vector<char> vc{'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
  std::string str(vc.cbegin(), vc.cend());

  std::cout << str << std::endl;

  return 0;
}
