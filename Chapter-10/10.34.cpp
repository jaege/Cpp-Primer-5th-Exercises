#include <vector>
#include <iostream>

int main() {
  std::vector<int> vi{0, 1, 2, 3, 4, 5};
  for (auto it = vi.crbegin(); it != vi.crend(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  return 0;
}
