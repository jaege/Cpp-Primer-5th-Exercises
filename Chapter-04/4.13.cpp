#include <iostream>

int main() {
  int i;
  double d;
  d = i = 3.5;
  std::cout << d << ' ' << i << std::endl;  // 3 3
  i = d = 3.5;
  std::cout << d << ' ' << i << std::endl;  // 3.5 3

  return 0;
}
