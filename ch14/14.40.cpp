// based on ex10.16.cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::string make_plural(size_t ctr, const std::string &word,
                        const std::string &ending = "s") {
  return (ctr > 1) ? word + ending : word;
}

void elimDups(std::vector<std::string> &words) {
  std::sort(words.begin(), words.end());
  auto end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

struct Shorter {
  bool operator()(const std::string &s1, const std::string &s2) const {
    return s1.size() < s2.size();
  }
};

struct Longer {
  Longer(size_t size) : sz(size) { }
  bool operator()(const std::string &s) const { return s.size() >= sz; }

private:
  size_t sz;
};

struct PrintString {
  PrintString(std::ostream &o = std::cout, char d = ' ')
      : os(o), delimiter(d) { }
  void operator()(const std::string &s) const { os << s << delimiter; }

private:
  std::ostream &os;
  char delimiter;
};

void biggies(std::vector<std::string> words,  // use value instead of reference
             std::vector<std::string>::size_type sz) {
  elimDups(words);
  std::stable_sort(words.begin(), words.end(), Shorter());
  auto iter = std::find_if(words.begin(), words.end(), Longer(sz));
  auto count = words.end() - iter;
  std::cout << count << " " << make_plural(count, "word") << " of length "
            << sz << " or longer." << std::endl;
  std::for_each(iter, words.end(), PrintString());
}

int main() {
  std::vector<std::string> words;
  for (std::string s; std::cin >> s; words.push_back(s)) { }
  biggies(words, 3);
  std::cout << std::endl;
  biggies(words, 5);

  return 0;
}
