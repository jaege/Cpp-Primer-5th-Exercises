#include <vector>
#include <algorithm>
#include <iostream>

class Foo {
public:
  Foo() = default;
  Foo(std::initializer_list<int> il) : data(il) { }

  Foo sorted() &&;
  Foo sorted() const &;

  void print() const;

private:
  std::vector<int> data;
};

Foo Foo::sorted() && {
  std::cout << "Foo Foo::sorted() &&" << std::endl;
  std::sort(data.begin(), data.end());
  return *this;
}

/* version 1 *
Foo Foo::sorted() const & {
  std::cout << "Foo Foo::sorted() const &" << std::endl;
  Foo ret(*this);
  std::sort(ret.data.begin(), ret.data.end());
  return ret;
}
/**/

/* version 2 *
Foo Foo::sorted() const & {
  std::cout << "Foo Foo::sorted() const &" << std::endl;
  Foo ret(*this);
  return ret.sorted();
  // Error: `ret` is an lvalue, thus it will recusively call itself infinitely.
}
/**/

/* version 3 */
Foo Foo::sorted() const & {
  std::cout << "Foo Foo::sorted() const &" << std::endl;
  return Foo(*this).sorted();
  // OK: `Foo(*this)` is an rvalue, thus it will call the rvalue version sort.
}
/**/

void Foo::print() const {
  std::cout << "<" << this << ">";
  for (const auto &i : data)
    std::cout << " " << i;
  std::cout << std::endl;
}

int main() {
  Foo f1; f1.print();
  Foo f2 { 9, 2, 6, 5, 3, 8, 4, 1, 7 }; f2.print();
  Foo f3 = f2.sorted(); f2.print(); f3.print();
  Foo f4 = Foo({ 2, 6, 5, 3, 8, 4, 1, 7 }).sorted(); f4.print();

  return 0;
}
