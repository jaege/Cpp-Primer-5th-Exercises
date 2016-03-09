#include <iostream>
#include <vector>
#include <deque>

template <typename C>
void print(const C &c) {
  for (typename C::size_type i = 0; i != c.size(); ++i)
    std::cout << c[i] << " ";
  std::cout << std::endl;
}

int main() {
  std::vector<int> vi { 1, 2, 3, 4, 5 };
  std::vector<double> vd { 1.1, 2.2, 3.3, 4.4, 5.5 };
  std::deque<int> di { 1, 2, 3, 4, 5 };

  print(vi);
  print(vd);
  print(di);

  return 0;
}
