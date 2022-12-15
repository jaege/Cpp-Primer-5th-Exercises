#include <iostream>

int main() {
  std::cout << -30 * 3 + 21 / 5 << std::endl;  // -86
  std::cout << -30 + 3 * 21 / 5 << std::endl;  // -18
  std::cout <<  30 / 3 * 21 % 5 << std::endl;  // 0
  std::cout << -30 / 3 * 21 % 4 << std::endl;  // -2

  return 0;
}
