#include <iostream>
#include <vector>

int main() {
  std::vector<int> iv;
  int i;
  while (std::cin >> i)
    iv.push_back(i);
  for (const auto & k : iv)
    std::cout << k << " ";
  std::cout << std::endl;

  return 0;
}
