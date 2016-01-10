int main() {
  int i, *const cp = &i;
  int *p1, *const p2 = p1;
  const int ic = 5, &r = ic;
  const int *const p3 = &ic;
  const int *p;

  i = ic;  // OK
  p1 = p3;  // Error: low-level const doesn't match
  p1 = &ic;  // Error: low-level const doesn't match
  p3 = &ic;  // Error: cannot assign value to a const variable
  p2 = p1;  // Error: cannot assign value to a const variable
  ic = *p3;  // Error: cannot assign value to a const variable

  return 0;
}
