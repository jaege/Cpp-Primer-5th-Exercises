#include <vector>
#include <iostream>

void printVecInt(const std::vector<int>::iterator bg,
                 const std::vector<int>::iterator ed) {
  if (bg == ed)
    return;
  std::cout << *bg << " ";
  printVecInt(bg + 1, ed);
}

int main() {
  std::vector<int> vi;
  int i;
  while (std::cin >> i)
    vi.push_back(i);

  printVecInt(vi.begin(), vi.end());

  return 0;
}
