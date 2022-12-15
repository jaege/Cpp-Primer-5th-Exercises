int main() {
  int i = 0, &r1 = i;
  double d = 0, &r2 = d;

  r2 = 3.14159;  // d = 3.14159
  r2 = r1;  // d = i
  i = r2;  // i = d
  r1 = d;  // i = d

  return 0;
}
