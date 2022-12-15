#include <vector>
#include <iostream>

int main() {
  std::vector<int> vi;

  // All of them will cause program terminate in VS2015.
  //int i1 = vi.at(0);
  //int i2 = vi[0];
  //int i3 = vi.front();
  //int i4 = *vi.begin();

  //std::cout << i1 << " " << i2 << " " << i3 << " " << i4 << std::endl;

  return 0;
}
