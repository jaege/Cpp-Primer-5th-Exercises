#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

int main() {
  std::vector<int> vi;
  for (int i; std::cin >> i; vi.push_back(i)) {}
  std::list<int> li;
  std::sort(vi.begin(), vi.end());  // This will change the original vector.
  std::unique_copy(vi.begin(), vi.end(), std::back_inserter(li));
  std::for_each(li.begin(), li.end(),
      [](int i) { std::cout << i << " ";});

  return 0;
}
