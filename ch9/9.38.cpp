#include <vector>
#include <iostream>

int main() {
  std::vector<int> vi;
  std::cout << "Size: " << vi.size()
            << "\tCapacity : " << vi.capacity() << std::endl;

  vi.push_back(1);
  std::cout << "Size: " << vi.size()
            << "\tCapacity : " << vi.capacity() << std::endl;

  for (std::vector<int>::size_type ix = 0; ix != 100; ++ix)
    vi.push_back(ix);
  std::cout << "Size: " << vi.size()
            << "\tCapacity : " << vi.capacity() << std::endl;

  vi.shrink_to_fit();
  std::cout << "Size: " << vi.size()
            << "\tCapacity : " << vi.capacity() << std::endl;

  return 0;
}
