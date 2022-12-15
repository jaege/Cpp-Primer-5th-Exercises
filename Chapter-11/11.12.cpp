#include <string>
#include <utility>
#include <vector>
#include <iostream>

int main() {
  std::vector<std::pair<std::string, int>> vp;
  std::string s;
  int i;
  while (std::cin >> s >> i)
    vp.push_back({s, i});
    //vp.push_back(std::make_pair(s, i));
    //vp.push_back(std::pair<std::string, int>(s, i));
  // I think the braced inititalizer is the most easy way.

  for (const auto &p : vp)
    std::cout << p.first << " : " << p.second << std::endl;

  return 0;
}
