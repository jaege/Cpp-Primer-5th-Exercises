#include <iostream>

void swapInt(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  swapInt(a, b);
  std::cout << a << " " << b << std::endl;

  // The reference version looks like easier to use, but the user must know
  // from other source that the function will change the value of the argument.

  return 0;
}
