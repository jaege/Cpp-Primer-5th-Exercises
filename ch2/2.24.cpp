int main() {
  int i = 42;
  void *p = &i;   // OK, a `void *` pointer can point to any type
  //long *lp = &i;  // Error, a `long *` pointer can not point to `int *`

  return 0;
}
