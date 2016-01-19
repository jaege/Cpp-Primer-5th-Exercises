#include <vector>
#include <list>
#include <iterator>
#include <iostream>

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  std::vector<int> iv(std::begin(ia), std::end(ia));
  std::list<int> il(std::begin(ia), std::end(ia));

  std::cout << "Before erase:" << std::endl;
  std::cout << "vector iv: ";
  for (const auto &i: iv)
    std::cout << i << " ";
  std::cout << std::endl;

  std::cout << "list   il: ";
  for (const auto &i: il)
    std::cout << i << " ";
  std::cout << std::endl;

  for (auto it = iv.begin(); it != iv.end(); )
    if (*it % 2)
      ++it;
    else
      it = iv.erase(it);

  for (auto it = il.begin(); it != il.end(); )
    if (*it % 2)
      it = il.erase(it);
    else
      ++it;

  std::cout << "After erase:" << std::endl;
  std::cout << "vector iv: ";
  for (const auto &i: iv)
    std::cout << i << " ";
  std::cout << std::endl;

  std::cout << "list   il: ";
  for (const auto &i: il)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
