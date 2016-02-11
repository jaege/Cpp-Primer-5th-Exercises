#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

// Valuelike version
class HasPtr {
  friend void swap(HasPtr &, HasPtr &);
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0) {}
  HasPtr(const char *cs) : ps(new std::string(cs)), i(0) {}
  HasPtr(const HasPtr &ori)
      : ps(new std::string(*ori.ps)), i(ori.i) {}
  ~HasPtr();

  HasPtr &operator=(const HasPtr &rhs);

  void swap(HasPtr &rhs);
  bool operator<(const HasPtr &rhs) const;

  const std::string &get() const { return *ps; }
  void set(const std::string &s) { *ps = s; }

private:
  std::string *ps;
  int i;
};

void HasPtr::swap(HasPtr &rhs) {
  std::cout << "HasPtr::swap(HasPtr &rhs) between <" << *ps
            << "> and <" << *rhs.ps << ">" << std::endl;
  using std::swap;
  swap(ps, rhs.ps);
  swap(i, rhs.i);
}

void swap(HasPtr &lhs, HasPtr &rhs) {
  std::cout << "swap(HasPtr &lhs, HasPtr &rhs) between <" << *lhs.ps
            << "> and <" << *rhs.ps << ">" << std::endl;
  lhs.swap(rhs);
}

HasPtr::~HasPtr() {
  delete ps;
}

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
  // This copy-assignment operator is correct even if the object is assigned to
  // itself. See ex13.11 for the wrong version.
  auto newps = new std::string(*rhs.ps);
  delete ps;
  ps = newps;
  i = rhs.i;
  return *this;
}

bool HasPtr::operator<(const HasPtr &rhs) const {
  //std::cout << "operator< between <" << *ps << "> and <"
  //          << *rhs.ps << ">" << std::endl;
  return *ps < *rhs.ps;
}

void testHasPtrVec(std::vector<HasPtr> &v) {
  std::cout << "\nBefore sort " << v.size() << " elements:\n";
  for (const auto &e : v)
    std::cout << e.get() << std::endl;
  std::cout << "\nSorting:\n";
  std::sort(v.begin(), v.end());
  std::cout << "\nAfter sort:\n";
  for (const auto &e : v)
    std::cout << e.get() << std::endl;
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

  hp1 = hp1;
  std::cout << "After `hp1 = hp1`: " << hp1.get() << std::endl;

  swap(hp1, hp2);
  std::cout << hp1.get() << std::endl;
  std::cout << hp2.get() << std::endl;

  swap(hp1, hp1);
  std::cout << hp1.get() << std::endl;

  std::vector<HasPtr> v{ "Hello", "World", "P", "Q", "R", "S", "T", "U",
      "ABC", "DEF", "AB", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L",
      "ABC", "DEF", "AB", "C", "D", "E", "J", "K", "L", "M", "N" };
  testHasPtrVec(v);
  // Note that if the total count of elements in vector is small (e.g. less
  // than 32 in VS2015), then no swap will be made when sorting.
  std::vector<HasPtr> v2{ "Hello", "World", "P", "Q", "R", "S", "T", "U",
      "ABC", "DEF", "AB", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L",
      "ABC", "DEF", "AB", "C", "D", "E", "J", "K", "L", "M", "N", "O" };
  testHasPtrVec(v2);


  return 0;
}
