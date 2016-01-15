#include <iostream>
#include <iterator>

//void print(const int arr[]) {
//  std::cout << "void print(const int arr[])" << std::endl;
//  // Cannot get the size of arr, unless by a marker in the array
//}

void print(int i) {
  std::cout << "void print(int i)" << std::endl;
  std::cout << i << std::endl;
}

void print(const int *bg, const int *ed) {
  std::cout << "void print(const int *bg, const int *ed)" << std::endl;
  while (bg != ed)
    std::cout << *bg++ << std::endl;
}

void print(const int arr[], size_t sz) {
  std::cout << "void print(const int arr[], size_t sz)" << std::endl;
  for (size_t i = 0; i != sz; ++i)
    std::cout << arr[i] << std::endl;
}

void print(const int (&arr)[2]) {
  std::cout << "void print(const int (&arr)[2])" << std::endl;
  for (auto & e : arr)
    std::cout << e << std::endl;
}

int main() {
  int i = 0, j[2] = {0, 1};
  std::cout << "i:" << std::endl;
  print(i);
  print(10);
  std::cout << "j:" << std::endl;
  print(std::begin(j), std::end(j));
  print(j, std::end(j) - std::begin(j));
  print(j);

  return 0;
}
