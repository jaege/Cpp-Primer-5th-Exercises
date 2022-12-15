#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
#include <iostream>

int main() {
  std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "Origin vector: ";
  for (const auto &i : vi)
    std::cout << i << " ";
  std::cout << std::endl;
  std::deque<int> vi1, vi2, vi3;
  std::cout << "Use inserter: ";
  std::copy(vi.begin(), vi.end(), std::inserter(vi1, vi1.end()));
  for (const auto &i : vi1)
    std::cout << i << " ";
  std::cout << std::endl;
  std::cout << "Use back_inserter: ";
  std::copy(vi.begin(), vi.end(), std::back_inserter(vi2));
  for (const auto &i : vi2)
    std::cout << i << " ";
  std::cout << std::endl;
  std::cout << "Use front_inserter: ";
  std::copy(vi.begin(), vi.end(), std::front_inserter(vi3));
  for (const auto &i : vi3)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
