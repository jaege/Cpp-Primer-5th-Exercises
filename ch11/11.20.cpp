#include <map>
#include <set>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <fstream>

std::string trimStr(std::string s) {
  constexpr char *punctuations{"\"'`:*-_;,.?!()[]{}"};
  for (auto &c : s)
    if (c >= 'A' && c <= 'Z') c -= 'A' - 'a';
  size_t bg = s.find_first_not_of(punctuations);
  if (bg == std::string::npos)
    return "";
  size_t ed = s.find_last_not_of(punctuations);
  return s.substr(bg, ed - bg + 1);
}

std::map<std::string, size_t> count_words(std::vector<std::string> &words) {
  std::map<std::string, size_t> counts;
  for (const auto &w : words) {
    //++counts[trimStr(w)];
    auto ret = counts.insert({trimStr(w), 1});
    if (!ret.second)
      ++ret.first->second;
    // The subscirpt way is easier to write, but hard to notice the fact that
    // it will add element if not existed.
  }
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
  for (const auto &w : words)
    std::cout << w << std::endl;
  auto counts = count_words(words);
  for (const auto &w: counts)
    std::cout << "\"" << w.first << "\" occurs " << w.second
              << (w.second > 1 ? " times." : " time.") << std::endl;

  return 0;
}
