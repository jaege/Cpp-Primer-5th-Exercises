#include <string>
#include <iostream>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &ori)
      : ps(new std::string(*ori.ps)), i(ori.i) {}

  HasPtr &operator=(const HasPtr &rhs);

  const std::string &get() const { return *ps; }
  void set(const std::string &s) { *ps = s; }

private:
  std::string *ps;
  int i;
};

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
  // This copy-assignment operator is wrong, see ex13.23 for correct version.
  delete ps;
  ps = new std::string(*rhs.ps);
  i = rhs.i;
  return *this;
}

int main() {
  HasPtr hp1 = "World";
  HasPtr hp2 = hp1;
  HasPtr hp3;
  hp3 = hp1;
  hp1.set("Hello");

  std::cout << hp1.get() << std::endl;
  std::cout << hp2.get() << std::endl;
  std::cout << hp3.get() << std::endl;

  return 0;
}
