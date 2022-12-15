#include <string>
#include <iostream>

struct Person {
  // Constructors which are part of interface should be public
  Person() = default;
  Person(const std::string &n) : name(n) {}
  Person(const std::string &n, const std::string &a)
      : name(n), address(a) {}
  Person(std::istream &);

  // member methods which are part of interface should be public
  std::string getName() const { return name; }
  std::string getAddress() const { return address; }

  // data members which are part of implementation shoule be private
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

Person::Person(std::istream &is) {
  read(is, *this);
}

int main() {
  return 0;
}
