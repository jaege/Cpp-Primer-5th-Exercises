#include <vector>
#include <iostream>
#include <sstream>

std::vector<int>::const_iterator
hasValue(std::vector<int>::const_iterator begin,
              std::vector<int>::const_iterator end,
              int k) {
  for (auto it = begin; it != end; ++it)
    if (k == *it)
      return it;
  return end;
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
  auto it = hasValue(vi.cbegin(), vi.cend(), k);
  if (it == vi.end())
    std::cout << "No found " << k << " in range" << std::endl;
  else
    std::cout << "Found " << *it
              << " at position " << it - vi.cbegin() << std::endl;

  return 0;
}
