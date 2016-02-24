#include <vector>
#include <algorithm>
#include <iostream>

struct Equal {
  typedef int ty;
  Equal(ty v) : val(v) { }
  bool operator()(ty rhs) {
    return val == rhs;
  }
private:
  ty val;
};

int main() {
  std::vector<int> vi { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int oldVal, newVal;
  std::cin >> oldVal >> newVal;
  std::replace_if(vi.begin(), vi.end(), Equal(oldVal), newVal);
  for (const auto &i : vi)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
