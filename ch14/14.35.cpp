#include <iostream>
#include <string>
#include <vector>

class PrintStr {
public:
  std::string operator()(std::istream &is) {
    std::string s;
    if(std::getline(is, s))
      return s;
    else
      return s;
  }
};

int main() {
  PrintStr ps;
  std::vector<std::string> vs;
  std::string s = ps(std::cin);
  while (!s.empty()) {
    vs.push_back(s);
    s = ps(std::cin);
  }
  for (const auto &l : vs)
    std::cout << "<" << l << ">" << std::endl;

  return 0;
}
