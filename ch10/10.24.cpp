#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

bool check_size(const std::string &s, std::string::size_type sz) {
  return s.size() >= sz;
}

bool check_size_v2(const std::string &s, int sz) {
  return sz >= 0 && !check_size(s, sz);
}

std::vector<int>::iterator
findLarger(std::vector<int> &vi, const std::string &s) {
  auto it = std::find_if(vi.begin(), vi.end(),
      std::bind(check_size_v2, s, std::placeholders::_1));
  return it;
}

int main() {
  std::string s;
  std::cin >> s;
  std::vector<int> vi;  // should be std::vector<size_t> vi;
  // The vector should contains unsigned type if we want to use check_size
  // directly, otherwise, use check_size_v2.
  //
  // Because the size_type of string is unsigned, when comparing with the
  // element in the vector, the element type will be converted to unsigned,
  // thus a negative value will become a big unsigned number.
  for (int i; std::cin >> i; vi.push_back(i)) {}
  std::cout << "The first element in vector that has a value greater than "
               "the length of string \"" << s << "\" is "
            << *findLarger(vi, s) << std::endl;

  return 0;
}
