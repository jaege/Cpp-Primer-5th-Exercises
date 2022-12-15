#include <iostream>

int &get(int *arry, int index) {
  return arry[index];
}

// The function is legal. It return a reference to the element at `index` in
// array `arry`. The reference return is lvalue, thus can be used to assign to
// the array.

int main() {
  int ia[10];
  for (int i = 0; i != 10; ++i)
    get(ia, i) = i;

  for (int i = 0; i != 10; ++i)
    std::cout << ia[i] << " ";
  std::cout << std::endl;

  return 0;
}
