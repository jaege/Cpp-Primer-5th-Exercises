#include <vector>
#include <memory>
#include <iostream>

typedef std::shared_ptr<std::vector<int>> share_vec_ptr;

share_vec_ptr factory_veci() {
  return std::make_shared<std::vector<int>>();
}

void set_veci(share_vec_ptr vip) {
  for (int i; std::cin >> i; vip->push_back(i)) {}
}

void print_veci(share_vec_ptr vip) {
  for (const auto &i : *vip)
    std::cout << i << " ";
  std::cout << std::endl;
}

int main() {
  auto p = factory_veci();
  set_veci(p);
  print_veci(p);

  return 0;
}
