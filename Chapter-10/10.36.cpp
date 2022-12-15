#include <vector>
#include <iostream>

int main() {
  std::vector<int> vi{0, 1, 2, 3, 4, 5, 0};
  auto rit = find(vi.crbegin(), vi.crend(), 0);
  std::cout << "The last " << *rit << " in vector is at position "
      << rit.base() - vi.cbegin() - 1 << std::endl;
      //<< vi.crend() - rit - 1 << std::endl;
  // rit.base() is the iterator one past element 0, just like end iterator

  return 0;
}
