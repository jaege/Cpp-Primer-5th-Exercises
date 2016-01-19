#include <vector>
#include <list>
#include <iostream>

int main() {
  std::list<int> li{1, 2, 3};
  std::vector<int> vi{4, 5, 6};

  std::vector<double> vd1(li.begin(), li.end());
  std::vector<double> vd2(vi.begin(), vi.end());

  std::cout << vd1[0] << " " << vd2[0] << std::endl;

  return 0;
}
