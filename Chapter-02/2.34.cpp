#include <iostream>

int main() {
  int i = 0, &r = i;
  const int ci = i, &cr = ci;

  auto a = r;  // int
  auto b = ci;  // int
  auto c = cr;  // int
  auto d = &i;  // int *
  auto e = &ci;  // const int *
  const auto f = ci;  // const int
  auto &g = ci;  // const int &

  std::cout << "a: before = " << a;
  a = 42;  // OK
  std::cout << "\tafter = " << a << std::endl;
  std::cout << "b: before = " << b;
  b = 42;  // OK
  std::cout << "\tafter = " << b << std::endl;
  std::cout << "c: before = " << c;
  c = 42;  // OK
  std::cout << "\tafter = " << c << std::endl;
  std::cout << "d: before = " << d;
  //d = 42;  // Error
  std::cout << "\tafter = " << d << std::endl;
  std::cout << "e: before = " << e;
  //e = 42;  // Error
  std::cout << "\tafter = " << e << std::endl;
  std::cout << "f: before = " << f;
  //f = 42;  // Error
  std::cout << "\tafter = " << f << std::endl;
  std::cout << "g: before = " << g;
  //g = 42;  // Error
  std::cout << "\tafter = " << g << std::endl;

  return 0;
}
