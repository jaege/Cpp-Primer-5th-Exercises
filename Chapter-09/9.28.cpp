#include <forward_list>
#include <string>
#include <iostream>

void insertAfterStr(std::forward_list<std::string> &fls,
          const std::string &s1,
          const std::string &s2) {
  auto pre = fls.before_begin();
  auto cur = fls.begin();
  while (cur != fls.end()) {
    if (*cur == s1) {
      fls.insert_after(cur, s2);
      return;
    } else {
      pre = cur++;
    }
  }
  fls.insert_after(pre, s2);
}

int main() {
  std::forward_list<std::string> fls{"s1", "s2", "s3"};

  for (const auto &s : fls)
    std::cout << s << " ";
  std::cout << std::endl;

  insertAfterStr(fls, "s2", "s4");

  for (const auto &s : fls)
    std::cout << s << " ";
  std::cout << std::endl;

  insertAfterStr(fls, "s5", "s6");

  for (const auto &s : fls)
    std::cout << s << " ";
  std::cout << std::endl;

  return 0;
}
