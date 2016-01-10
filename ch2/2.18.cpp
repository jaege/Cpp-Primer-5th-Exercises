#include <iostream>

int main() {
  int i;
  int *ip = &i;

  *ip = 10;
  std::cout << i << " " << *ip << std::endl;  // 10 10
  i = 5;
  std::cout << i << " " << *ip << std::endl;  // 5 5

  return 0;
}
