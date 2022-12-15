#include <iostream>
#include <string>

std::istream &read(std::istream &is) {
  //auto old_state = is.rdstate();
  is.clear();
  std::string str;
  while (is >> str)
    std::cout << str << " ";
  std::cout << std::endl;
  is.clear();
  //is.setstate(old_state);
  return is;
}

int main() {
  read(std::cin);

  return 0;
}
