#include <iostream>

template <typename T, size_t N>
constexpr size_t size_arr(T (&arr)[N]) {
  return N;
}


int main() {
  int arr[] = { 1, 2, 3, 4, 5 };
  constexpr size_t sz = size_arr(arr);

  std::cout << sz << " " << size_arr(arr) << std::endl;

  return 0;
}
