#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cout << s[0] << std::endl;  // The subscript is out of range, result is undefined.

  return 0;
}
