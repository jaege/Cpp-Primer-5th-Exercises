#include <string>
#include <iostream>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &ori) {
    auto nps = ori.ps;
        delete ps;
        ps = new string(*nps);
  }

  const std::string &get() const { return *ps; }
  void set(const std::string &s) { *ps = s; }

private:
  std::string *ps;
  int i;
};

int main() {
  HasPtr hp1 = "World";
  HasPtr hp2 = hp1;
  hp1.set("Hello");

  std::cout << hp1.get() << " " << hp2.get() << std::endl;

  return 0;
}
