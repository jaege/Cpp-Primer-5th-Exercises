#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

bool longStr(const std::string &s) {
  return s.size() >= 5;
}

int main() {
  std::vector<std::string> words;
  for (std::string s; std::cin >> s; words.push_back(s)) {}
  auto long_bg = std::partition(words.begin(), words.end(), longStr);
  for (auto it = words.begin(); it != long_bg; ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  return 0;
}
