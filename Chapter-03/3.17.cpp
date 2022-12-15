#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> sv;
  std::string s;
  while (std::cin >> s)
    sv.push_back(s);
  for (auto &elem : sv)
    for (auto &c : elem)
      c = toupper(c);
  for (decltype(sv.size()) i = 0; i != sv.size(); ++i) {
    std::cout << sv[i] << '\t';
    if ((i + 1) % 8 == 0)
      std::cout << std::endl;
  }

  return 0;
}
