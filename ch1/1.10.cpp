#include <iostream>

int main() {
  int val = 10;
  while (val >= 0)
    std::cout << val-- << " ";
  std::cout << std::endl;
  return 0;
}
