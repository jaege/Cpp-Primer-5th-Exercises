#include <iostream>

int main() {
  int x[10];
  int *p = x;
  std::cout << sizeof(x) / sizeof(*x) << std::endl;  // 10
  std::cout << sizeof(p) / sizeof(*p) << std::endl;  // the size of a pointer / the size of an int

  return 0;
}
