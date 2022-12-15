// based on ex16.19
#include <iostream>
#include <vector>
#include <deque>
#include <list>

template <typename C>
void print(const C &c) {
  //for (auto it = c.begin(); it != c.end(); ++it)
  for (typename C::const_iterator it = c.begin(); it != c.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

int main() {
  std::vector<int> vi { 1, 2, 3, 4, 5 };
  std::vector<double> vd { 1.1, 2.2, 3.3, 4.4, 5.5 };
  std::deque<int> di { 1, 2, 3, 4, 5 };
  std::list<int> li { 1, 2, 3, 4, 5 };

  print(vi);
  print(vd);
  print(di);
  print(li);

  return 0;
}
