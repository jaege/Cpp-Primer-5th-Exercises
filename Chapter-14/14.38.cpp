#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

class StrRange {
public:
  StrRange(size_t l, size_t h) : low(l), high(h) { }
  bool operator()(const std::string &s) const {
    return s.size() >= low && s.size() <= high;
  }

private:
  size_t low;
  size_t high;
};

int main() {
  std::string filename;
  std::cin >> filename;
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cerr << "Can not open file: " << filename << std::endl;
    return -1;
  }
  std::istream_iterator<std::string> iter(ifs), eof;
  std::cout << std::count_if(iter, eof, StrRange(1, 10)) << std::endl;

  return 0;

}
