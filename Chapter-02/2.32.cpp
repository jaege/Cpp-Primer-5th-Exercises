#include <cstdlib>

int main() {
  //int null = 0, *p = null;  // Error: type mismatch

  // Method 1
  const int null1 = 0;
  int *p1 = null1;

  // Method 2
  int *p2 = nullptr;

  // Method 3
  int *p3 = 0;

  // Method 4 (may need include `cstdlib`)
  int *p4 = NULL;

  // Method 5
  constexpr int null2 = 0;
  int *p5 = null2;

  return 0;
}
