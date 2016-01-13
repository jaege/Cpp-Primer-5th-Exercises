#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void readVector(std::vector<int> &v) {
  std::string str;
  std::getline(std::cin, str);
  std::stringstream ss(str);
  int i;
  while(ss >> i)
    v.push_back(i);
  //for (const auto &e : v)
  //  std::cout << e << " ";
  //std::cout << std::endl;
}

bool isPrefix(const std::vector<int> &v1, const std::vector<int> &v2) {
  auto it1 = v1.cbegin(), it2 = v2.cbegin();
  for (; it1 != v1.cend() && it2 != v2.cend(); ++it1, ++it2)
    if (*it1 != *it2)
      break;
  return it1 == v1.cend() || it2 == v2.cend();
}

int main() {
  std::vector<int> v1, v2;
  readVector(v1);
  readVector(v2);
  std::cout << (isPrefix(v1, v2) ? "true" : "false") << std::endl;

  return 0;
}
