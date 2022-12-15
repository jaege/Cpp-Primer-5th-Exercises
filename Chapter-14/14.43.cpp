#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
  using namespace std::placeholders;
  int n;
  std::cin >> n;
  std::vector<int> vi { 12, 34, 56, 78, 90, 123, 456, 789 };
  auto it = std::find_if_not(vi.begin(), vi.end(),
      std::bind(std::modulus<int>(), _1, n));
  if (it != vi.end())
    std::cout << n << " is divisible by " << *it << std::endl;
  else
    std::cout << "Find nothing." << std::endl;

  return 0;
}
