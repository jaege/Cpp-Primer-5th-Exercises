#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

std::ostream &print(std::ostream &os, const std::vector<std::string> &vs) {
  for (const auto &i : vs)
    os << i << " ";
  return os;
}

void elimDups(std::vector<std::string> &words) {
  print(std::cout, words) << words.size() << std::endl;
  std::sort(words.begin(), words.end());
  print(std::cout, words) << words.size() << std::endl;
  auto end_unique = std::unique(words.begin(), words.end());
  print(std::cout, words) << words.size() << std::endl;
  words.erase(end_unique, words.end());
  print(std::cout, words) << words.size() << std::endl;
}

int main() {
  std::vector<std::string> words;
  for (std::string s; std::cin >> s; words.push_back(s)) {}
  elimDups(words);

  return 0;
}
