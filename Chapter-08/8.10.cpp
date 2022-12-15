#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

int main() {
  std::vector<std::string> vs;
  std::string filename;
  std::cin >> filename;
  std::ifstream in(filename);
  if (!in) {
    std::cerr << "Fail to open file: " << filename << std::endl;
    return -1;
  }
  for (std::string line; std::getline(in, line); vs.push_back(line)) {}
  for (const auto &e : vs) {
    std::istringstream iss(e);
    for (std::string word; iss >> word; std::cout << word << std::endl) {}
  }

  return 0;
}
