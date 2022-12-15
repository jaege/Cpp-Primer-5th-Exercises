#include <iostream>

void resetInt(int &i) {
  i = 0;
}

int main() {
  int a;
  std::cin >> a;
  std::cout << "before reset: " << a << std::endl;
  resetInt(a);
  std::cout << "after reset:  " << a << std::endl;

  return 0;
}
