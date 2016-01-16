#include <string>
#include <iostream>

struct Person {
  std::string getName() const { return name; }
  std::string getAddress() const { return address; }

  std::string name;
  std::string address;
};

std::istream &read(std::istream &is, Person &rhs) {
  is >> rhs.name >> rhs.address;
  return is;
}

std::ostream &print(std::ostream &os, const Person &rhs) {
  os << rhs.getName() << " " << rhs.getAddress();
  return os;
}

int main() {
  Person p1;
  read(std::cin, p1);
  print(std::cout, p1) << std::endl;

  return 0;
}
