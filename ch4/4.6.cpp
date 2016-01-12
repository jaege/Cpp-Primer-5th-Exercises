#include <iostream>

int main() {
  int i;
  std::cin >> i;
  if (i % 2)
    std::cout << i << " is an odd number." << std::endl;
  else
    std::cout << i << " is an even number." << std::endl;

  return 0;
}
