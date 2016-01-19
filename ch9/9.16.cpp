#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

int main() {
  std::list<int> li;
  std::vector<int> vi;

  std::string s;
  std::cout << "Please enter list<int> li:   ";
  std::getline(std::cin, s);
  std::istringstream iss(s);
  int k;
  while(iss >> k)
    li.push_back(k);

  std::cout << "Please enter vector<int> vi: ";
  std::getline(std::cin, s);
  iss.clear();
  iss.str(s);
  while(iss >> k)
    vi.push_back(k);

  size_t i = 0;
  auto lit = li.cbegin();
  auto vit = vi.cbegin();
  for (; lit != li.cend() && vit != vi.cend(); ++lit, ++vit)
      if (*lit < *vit) {
        std::cout << "li < vi" << std::endl;
        return 0;
      } else if (*lit > *vit) {
        std::cout << "li > vi" << std::endl;
        return 0;
      }
  if (li.size() == vi.size())
    std::cout << "li == vi" << std::endl;
  else if (lit == li.end())
    std::cout << "li < vi" << std::endl;
  else
    std::cout << "li > vi" << std::endl;

  return 0;
}
