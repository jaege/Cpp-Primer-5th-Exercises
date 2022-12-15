#include <iostream>
#include "Chapter6.h"

int main() {
  int n;
  while (std::cin >> n)
    std::cout << n << "! = " << fact(n) << std::endl;

  return 0;
}
