#include "Chapter6.h"

int fact(int n) {  // Ignore overflow
  if (n < 1) return n;
  int k = n;
  while (--n)
    k *= n;
  return k;
}
