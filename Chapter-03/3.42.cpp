#include <iostream>
#include <vector>
#include <iterator>

int main() {
  std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8};
  int ia[10];
  int *bg = ia;
  int *ed = ia + iv.size();
  for (const auto &i : iv)
    *bg++ = i;

  for (bg = ia; bg != ed; ++bg)
    std::cout << *bg << ' ';
  std::cout << std::endl;

  return 0;
}
