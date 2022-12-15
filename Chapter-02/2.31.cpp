int main() {
  int i;
  const int v2 = 0;  // v2 has top-level const
  int v1 = v2;
  int *p1 = &v1, &r1 = v1;
  const int *p2 = &v2, *const p3 = &i, &r2 = v2;  // p2 has low-level const
                                                  // p3 has both low-level and top-level const
                                                  // r2 has low-level const

  r1 = v2;  // OK
  //p1 = p2;  // Error: low-level const doesn't match
  p2 = p1;  // OK
  //p1 = p3;  // Error: low-level const doesn't match
  p2 = p3;  // OK

  //int &r = v2; // Error: low-level const doesn't match

  // The assignment can add but not lose the low-level `const` qualifier.
  // The assignment will ignore top-level `const` qualifier.

  return 0;
}
