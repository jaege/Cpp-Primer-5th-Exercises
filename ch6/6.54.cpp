#include <vector>
#include <iostream>

int foo(int, int);
int bar(int, int);

int main() {
  std::vector<int (*)(int, int)> vf;

  vf.push_back(foo);
  vf.push_back(bar);

  vf[0](1, 2);
  vf[1](3, 4);

  for (const auto &e : vf)
    e(9, 9);

  return 0;
}

int foo(int a, int b) {
  std::cout << "Called foo(" << a << ", " << b << ")" << std::endl;
  return 0;
}

int bar(int a, int b) {
  std::cout << "Called bar(" << a << ", " << b << ")" << std::endl;
  return 0;
}
