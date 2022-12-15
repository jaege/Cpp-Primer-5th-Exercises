#include <string>
#include <iostream>

int main() {
  std::string numbers("0123456789"), name("r2d2");
  auto pos = numbers.find(name);  // std::string::npos
  if (pos != std::string::npos)
    std::cout << pos << std::endl;
  else
    std::cout << "npos" << std::endl;

  return 0;
}
