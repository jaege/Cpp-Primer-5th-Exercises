#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> read(const std::string &filename) {
  std::ifstream in(filename);
  std::vector<std::string> vs;
  if (in) {
    for (std::string s; std::getline(in, s);)
      vs.push_back(s);
  } else {
    std::cerr << "Fail to open file: " << filename << std::endl;
  }
  return vs;
}

int main() {
  std::string filename;
  std::cin >> filename;
  auto vs = read(filename);
  for (decltype(vs.size()) i = 0; i != vs.size(); ++i)
    std::cout << i + 1 << "\t: " << vs[i] << std::endl;

  return 0;
}
