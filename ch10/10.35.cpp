#include <vector>
#include <iostream>

int main() {
  std::vector<int> vi{0, 1, 2, 3, 4, 5};
  for (auto it = --vi.end(); it + 1 != vi.begin(); --it)
    std::cout << *it << " ";
  std::cout << std::endl;

  return 0;
}
