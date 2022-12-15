#include <iostream>

int main() {
  int a = 3, b = 4;
  decltype(a) c = a;  // `c` is `int`
  decltype(a = b) d = a;  // `d` is `int &` to a, the expression is not evaluated
  std::cout << a << " " << b << " " << c << " " << d << std::endl;  // 3 4 3 3

  return 0;
}
