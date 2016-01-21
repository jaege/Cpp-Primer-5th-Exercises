#include <forward_list>
#include <iostream>

int main() {
  std::forward_list<int> fli{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto pre = fli.before_begin();
  auto cur = fli.begin();
  while (cur != fli.end()) {
    if (*cur % 2) {
      cur = fli.erase_after(pre);
    } else {
      pre = cur;
      ++cur;
    }
  }

  for (const auto &i : fli)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
