#include <list>
#include <deque>
#include <iostream>

int main() {
  std::list<int> input;
  std::deque<int> even, odd;

  for (int i; std::cin >> i; )
    input.push_back(i);

  for (auto it = input.cbegin(); it != input.cend(); ++it)
    if (*it % 2)
      odd.push_back(*it);
    else
      even.push_back(*it);

  std::cout << "Odd: ";
  for (const auto &i : odd)
    std::cout << i << " ";
  std::cout << std::endl;

  std::cout << "Even: ";
  for (const auto &i : even)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
