#include <string>
#include <vector>
#include <iostream>

int main() {
  std::vector<std::string> vs;
  for (std::string number; std::cin >> number; vs.push_back(number)) {}
  //int sum = 0;
  double sum = 0;
  for (const auto &s : vs)
    //sum += stoi(s);
    sum += stod(s);
  std::cout << "The sum is " << sum << std::endl;

  return 0;
}
