#include <iostream>

int main() {
  //(a)
  //int i, *const cp;  // Error: a const pointer must be initialized
  //(b)
  //int *p1, *const p2;  // Error: a const pointer must be initialized
  //(c)
  //const int ic, &r = ic;  // Error: const int `ic` must be initialized
  //(d)
  //const int *const p3;  // Error: a const pointer must be initialized
  //(e)
  const int *p;  // OK

  return 0;
}
