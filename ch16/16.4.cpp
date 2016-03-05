#include <vector>
#include <list>
#include <string>
#include <iostream>

template <typename InIter, typename Val>
InIter find_element(InIter bg, InIter ed, const Val &v) {
  for (; bg != ed; ++bg)
    if (*bg == v)
      return bg;
  return bg;
}

int main() {
  std::vector<int> vi { 1, 2, 3, 4, 5 };
  auto it1 = find_element(vi.begin(), vi.end(), 3);
  if (it1 != vi.end())
    std::cout << *it1 << std::endl;
  else
    std::cout << "not found" << std::endl;
  auto it2 = find_element(vi.begin(), vi.end(), 8);
  if (it2 != vi.end())
    std::cout << *it2 << std::endl;
  else
    std::cout << "not found" << std::endl;

  std::list<std::string> ls { "abc", "def", "gh" };
  auto it3 = find_element(ls.begin(), ls.end(), "gh");
  if (it3 != ls.end())
    std::cout << *it3 << std::endl;
  else
    std::cout << "not found" << std::endl;
  auto it4 = find_element(ls.begin(), ls.end(), "hello");
  if (it4 != ls.end())
    std::cout << *it4 << std::endl;
  else
    std::cout << "not found" << std::endl;

  return 0;
}
