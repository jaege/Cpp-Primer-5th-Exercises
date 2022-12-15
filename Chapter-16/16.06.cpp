#include <iostream>

template <typename T, size_t N>
T *begin_arr(T (&arr)[N]) {
  return arr;
}

template <typename T, size_t N>
T *end_arr(T (&arr)[N]) {
  return arr + N;
}

int main() {
  int arr[] = { 1, 2, 3, 4, 5 };
  for (auto it = begin_arr(arr); it != end_arr(arr); ++it)
    std::cout << *it << std::endl;

  return 0;
}
