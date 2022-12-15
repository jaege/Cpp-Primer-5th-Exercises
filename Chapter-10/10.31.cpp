#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

int main() {
  std::istream_iterator<int> i_iter(std::cin), i_eof;
  std::vector<int> vi(i_iter, i_eof);
  std::sort(vi.begin(), vi.end());
  std::ostream_iterator<int> o_iter(std::cout, " ");
  std::unique_copy(vi.begin(), vi.end(), o_iter);

  return 0;
}
