#include <map>
#include <set>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <fstream>

std::map<std::string, size_t> count_words(std::vector<std::string> &words) {
  std::map<std::string, size_t> counts;
  for (const auto &w : words)
    ++counts[w];
  return counts;
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
  auto counts = count_words(words);
  for (const auto &w: counts)
    std::cout << w.first << " occurs " << w.second
              << (w.second > 1 ? " times." : " time.") << std::endl;

  return 0;
}
