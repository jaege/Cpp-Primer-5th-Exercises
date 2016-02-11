#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

//#define COPY_N_SWAP_ASSIGNMENT_OP

// Valuelike version
class HasPtr {
  friend void swap(HasPtr &, HasPtr &);
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0) {}
  HasPtr(const char *cs) : ps(new std::string(cs)), i(0) {}

  ~HasPtr();
  HasPtr(const HasPtr &rhs)
      : ps(new std::string(*rhs.ps)), i(rhs.i) {
    std::cout << "HasPtr::HasPtr(const HasPtr &rhs)" << std::endl;
  }
  // When the `HasPtr` does not define move-assignment operator,
  // copy-assignment operator is used when a move-assignment operator is
  // needed, which may leads to one more time of copying and destroying the
  // underlying data members.
#ifndef COPY_N_SWAP_ASSIGNMENT_OP
  HasPtr &operator=(const HasPtr &rhs);
#endif
  HasPtr(HasPtr &&rhs) noexcept : ps(rhs.ps), i(rhs.i) {
    rhs.ps = nullptr;
    std::cout << "HasPtr::HasPtr(HasPtr &&rhs)" << std::endl;
  }
#ifndef COPY_N_SWAP_ASSIGNMENT_OP
  HasPtr &operator=(HasPtr &&rhs) noexcept;
#endif

  // Copy-and-swap assignment operator as follows acts as both the
  // copy-assignment and move-assignment operator.
#ifdef COPY_N_SWAP_ASSIGNMENT_OP
  HasPtr &operator=(HasPtr rhs);
#endif

  void swap(HasPtr &rhs);
  bool operator<(const HasPtr &rhs) const;

  const std::string &get() const { return *ps; }
  void set(const std::string &s) { *ps = s; }

private:
  std::string *ps;
  int i;
};

void HasPtr::swap(HasPtr &rhs) {
  std::cout << "HasPtr::swap(HasPtr &rhs)" << std::endl;
  using std::swap;
  swap(ps, rhs.ps);
  swap(i, rhs.i);
}

void swap(HasPtr &lhs, HasPtr &rhs) {
  std::cout << "swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
  lhs.swap(rhs);
}

HasPtr::~HasPtr() {
  delete ps;
}

#ifndef COPY_N_SWAP_ASSIGNMENT_OP
HasPtr &HasPtr::operator=(const HasPtr &rhs) {
  std::cout << "HasPtr::operator=(const HasPtr &rhs)" << std::endl;
  auto newps = new std::string(*rhs.ps);
  delete ps;
  ps = newps;
  i = rhs.i;
  return *this;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept {
  std::cout << "HasPtr::operator=(HasPtr &&rhs)" << std::endl;
  if (this != &rhs) {
    ps = rhs.ps;
    i = rhs.i;
    rhs.ps = nullptr;
  }
  return *this;
}
#endif

#ifdef COPY_N_SWAP_ASSIGNMENT_OP
HasPtr &HasPtr::operator=(HasPtr rhs) {
  ::swap(*this, rhs);
  return *this;
}
#endif

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
  HasPtr hp1 = "str1";

  std::cout << "=== copy constructor ===\n";
  HasPtr hp2 = hp1;
  std::cout << hp1.get() << std::endl;
  std::cout << hp2.get() << std::endl;

  std::cout << "=== copy-assignment operator ===\n";
  HasPtr hp3;
  hp3 = hp1;
  std::cout << hp1.get() << std::endl;
  std::cout << hp3.get() << std::endl;

  std::cout << "=== move constructor ===\n";
  HasPtr hp4 = std::move(hp1);
  //std::cout << hp1.get() << std::endl;  // nullptr
  std::cout << hp4.get() << std::endl;

  std::cout << "=== move-assignment operator ===\n";
  hp1 = std::move(hp4);
  std::cout << hp1.get() << std::endl;
  //std::cout << hp4.get() << std::endl;  // nullptr

  return 0;
}
