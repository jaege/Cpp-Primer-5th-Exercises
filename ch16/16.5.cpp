#include <iostream>

template <typename T, size_t N>
void print(const T (&arr)[N]) {
  for (size_t i = 0; i != N; ++i)
    std::cout << arr[i] << std::endl;
}

struct C {
  int i;
  double d;
};

std::ostream &operator<<(std::ostream &os, const C &c) {
  return os << c.i << " " << c.d;
}

int main() {
  int a[] = { 1, 2, 3, 4 };
  print(a);

  char b[] = "abcde";
  print(b);  // will print the trailing `\0`

  C c[] = { 1, 1.1, 2, 2.2, 3, 3.3 };
  print(c);

  return 0;
}
