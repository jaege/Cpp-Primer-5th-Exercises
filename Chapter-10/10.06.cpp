#include <vector>
#include <list>
#include <iostream>

int main() {
  std::vector<int> vi(10, 1);
  std::list<int> li(10, 1);
  std::fill_n(vi.begin(), vi.size(), 0);
  std::fill_n(li.begin(), li.size(), 0);
  std::cout << vi.back() << " " << li.back() << std::endl;

  return 0;
}
