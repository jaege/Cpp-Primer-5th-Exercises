// By using a `set`, we can avoid removing duplicates by ourself.
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <fstream>
#include <algorithm>

void elimDups(std::vector<std::string> &words) {
  std::sort(words.begin(), words.end());
  auto end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

int main() {
  std::string filename;
  std::cin >> filename;
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cerr << "Cannot open file: " << filename << std::endl;
    return -1;
  }
  std::istream_iterator<std::string> i_iter(in), eof;
  std::vector<std::string> words(i_iter, eof);
  for (const auto &w : words)
    std::cout << w << std::endl;
  std::cout << "\nAfter remove duplicates:\n";
  elimDups(words);
  for (const auto &w : words)
    std::cout << w << std::endl;

  return 0;
}
