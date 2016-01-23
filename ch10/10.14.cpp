#include <iostream>

int main() {
  auto sum = [](int a, int b) { return a + b; };

  int a, b;
  std::cin >> a >> b;
  std::cout << a << " + " << b << " = " << sum(a, b) << std::endl;

  return 0;
}
