#include <iostream>

int main() {
  int n;
  auto isZero = [&n] { return n > 0 ? --n, false : true; };
  // Use comma expression to return bool value
  std::cin >> n;

  while (!isZero())
    std::cout << n << std::endl;
  isZero();
  std::cout << n << std::endl;
  //std::cout << typeid(isZero()).name() << std::endl;

  return 0;
}
