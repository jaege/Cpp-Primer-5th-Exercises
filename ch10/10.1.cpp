#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int val;
  std::cin >> val;
  std::vector<int> vi;
  for (int i; std::cin >> i; vi.push_back(i)) {}
  std::cout << "Value \"" << val << "\" occours "
            << std::count(vi.begin(), vi.end(), val) << " time(s) in sequence."
            << std::endl;

  return 0;
}
