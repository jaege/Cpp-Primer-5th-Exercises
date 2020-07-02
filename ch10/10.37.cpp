#include <vector>
#include <list>
#include <iostream>

int main() {
  std::vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> li(vi.rbegin() + 3, vi.rend() - 2);
  for (const auto &i : li)
    std::cout << i << " ";

  return 0;
}
