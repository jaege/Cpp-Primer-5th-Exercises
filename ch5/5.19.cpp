#include <iostream>
#include <string>

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;
  do {
    std::cout << ( s1 == s2 ? "Equal"
                            : s1 < s2 ? "First small" : "Second small")
              << std::endl;
  } while (std::cin >> s1 >> s2);

  return 0;
}
