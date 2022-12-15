#include <vector>
#include <list>
#include <string>
#include <iostream>

int main() {
  std::list<char *> lc{"aaa", "bbb", "ccc"};
  std::vector<std::string> vs;

  vs.assign(lc.begin(), lc.end());

  std::cout << vs[0] << std::endl;

  return 0;
}
