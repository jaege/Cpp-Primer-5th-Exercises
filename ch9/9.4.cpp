#include <vector>
#include <iostream>
#include <sstream>

bool hasValue(std::vector<int>::const_iterator begin,
              std::vector<int>::const_iterator end,
              int k) {
  for (auto it = begin; it != end; ++it)
    if (k == *it)
      return true;
  return false;
}

int main() {
  std::string str;
  std::getline(std::cin, str);
  std::istringstream iss(str);
  std::vector<int> vi;
  int k;
  while (iss >> k)
    vi.push_back(k);
  std::cin >> k;
  std::cout << hasValue(vi.cbegin(), vi.cend(), k) << std::endl;

  return 0;
}
