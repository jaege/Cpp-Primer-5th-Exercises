int main() {
  int i;
  const int v2 = 0;  // v2 has top-level const
  int v1 = v2;
  int *p1 = &v1, &r1 = v1;
  const int *p2 = &v2, *const p3 = &i, &r2 = v2;  // p2 has low-level const
                                                  // p3 has both low-level and top-level const
                                                  // r2 has low-level const
  return 0;
}
