#include <algorithm>
#include <iostream>
#include <list>
#include <string>

int main() {
  std::string val;
  std::cin >> val;
  std::list<std::string> vi;
  for (std::string i; std::cin >> i; vi.push_back(i)) {}
  std::cout << "Value \"" << val << "\" occours "
            << std::count(vi.begin(), vi.end(), val) << " time(s) in sequence."
            << std::endl;

  // The only changes we made are the type of the variables, the function call
  // is still the same with ex10.1.

  return 0;
}
