#include <iostream>

int main() {
  int x, y;
  std::cin >> x >> y;
  auto sum = [x](int i) { return x + i; };
  // The lamda must be defined after we read x, otherwise it will capture the
  // undefined value of x.
  std::cout << x << " + " << y << " = " << sum(y) << std::endl;

  return 0;
}
