#include <vector>
#include <iostream>

std::vector<int> *factory_veci() {
  return new std::vector<int>;
}

void set_veci(std::vector<int> *vip) {
  for (int i; std::cin >> i; vip->push_back(i)) {}
}

void print_veci(std::vector<int> *vip) {
  for (const auto &i : *vip)
    std::cout << i << " ";
  std::cout << std::endl;
}

int main() {
  auto *p = factory_veci();
  set_veci(p);
  print_veci(p);
  delete p;

  return 0;
}
