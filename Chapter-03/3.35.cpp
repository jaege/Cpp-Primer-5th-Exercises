#include <iterator>
#include <iostream>

int main() {
  int ia[10];
  for (const auto &e : ia)
    std::cout << e << ' ';
  std::cout << std::endl;

  for (int *bg = std::begin(ia), *ed = std::end(ia); bg != ed; ++bg)
    *bg = 0;

  for (const auto &e : ia)
    std::cout << e << ' ';
  std::cout << std::endl;

  return 0;
}
