#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int main() {
  std::string filename;
  std::cin >> filename;
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cerr << "Can not open file: " << filename << std::endl;
    return -1;
  }
  std::istream_iterator<std::string> iter(in), eof;
  //std::vector<std::string> vs;
  //while (iter != eof)
  //  vs.push_back(*iter++);
  std::vector<std::string> vs(iter, eof);  // The shorter way
  for (const auto &s: vs)
    std::cout << s << std::endl;

  return 0;
}
