#include <vector>
#include <iostream>

int main() {
  std::vector<int> v1 = {1, 3, 5, 7, 9, 12};
  std::vector<int> v2 = {1, 3, 9};

  std::cout << (v1 < v2 ? "v1 < v2" : "v2 < v1") << std::endl;

  return 0;
}
