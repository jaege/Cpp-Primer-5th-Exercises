#include <iostream>
#include <string>

int main() {
  std::string s;
  if (std::cin >> s) {
    for (char c : s)
      c = 'X';  // will not change s
  }
  std::cout << s << std::endl;

  return 0;
}
