#include <iostream>

int main() {
  int bg = 0, ed = 0;
  std::cout << "Enter the number of begin and end: ";
  std::cin >> bg >> ed;
  while (bg <= ed)
    std::cout << bg++ << " ";
  std::cout << std::endl;
  return 0;
}
