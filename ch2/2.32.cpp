#include <cstdlib>

int main() {
  //int null = 0, *p = null;  // Error: type mismatch

  // Method 2
  int *p2 = nullptr;

  // Method 3
  int *p3 = 0;

  // Method 4 (may need include `cstdlib`)
  int *p4 = NULL;

  return 0;
}
