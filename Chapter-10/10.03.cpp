#include <numeric>
#include <vector>
#include <iostream>

int main() {
  std::vector<int> vi;
  for (int i; std::cin >> i; vi.push_back(i)) {}
  std::cout << "The sum of the sequence is "
            << std::accumulate(vi.cbegin(), vi.cend(), 0) << std::endl;

  return 0;
}
