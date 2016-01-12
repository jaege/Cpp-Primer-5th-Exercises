#include <iostream>
#include <vector>

int main() {
  std::vector<int> iv;
  int i;
  while (std::cin >> i)
    iv.push_back(i);
  for (auto &elem : iv)
    elem = elem % 2 ? elem + elem : elem;
  for (const auto &elem : iv)
    std::cout << elem << ' ';
  std::cout << std::endl;

  return 0;
}
