#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec(10);
  std::vector<int>::size_type cnt = ivec.size();
  for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
    ivec[ix] = cnt;
  for (const auto &e : ivec)
    std::cout << e << " ";
  std::cout << std::endl;

  // Because we don't need the value returned by postfix operator, and making a
  // copy of an object may be a heavy operation, so prefix operator is prefered
  // here.

  cnt = ivec.size();
  for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    ivec[ix] = cnt;
  for (const auto &e : ivec)
    std::cout << e << " ";
  std::cout << std::endl;

  // The results are same.

  return 0;
}
