int _;  // Error: start with `_` (May not warn by compiler)
int main() {
  //int double = 3.14;  // Error: reserved key word
  int _;  // OK
  //int catch-22;  // Error: `-` in name
  //int 1_or_2 = 1;  // Error: start with number
  double Double = 3.14;  // OK

  int _i2;  // OK

  return 0;
}
