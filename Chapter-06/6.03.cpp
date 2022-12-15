#include <iostream>

int fact(int n) {  // Ignore overflow
  if (n < 1) return n;
  int k = n;
  while (--n)
    k *= n;
  return k;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << n << "! = " << fact(n) << std::endl;

  return 0;
}
