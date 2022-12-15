#include <list>
#include <string>
#include <iostream>
#include <algorithm>

std::ostream &print(std::ostream &os, const std::list<std::string> &ls) {
  for (const auto &i : ls)
    os << i << " ";
  return os;
}

void elimDups(std::list<std::string> &words) {
  print(std::cout, words) << words.size() << std::endl;
  words.sort();
  print(std::cout, words) << words.size() << std::endl;
  words.unique();
  print(std::cout, words) << words.size() << std::endl;
}

int main() {
  std::list<std::string> words;
  for (std::string s; std::cin >> s; words.push_back(s)) {}
  elimDups(words);

  return 0;
}
