int main () {
  int i = 0;

  //double *dp = &i;  // Error: `dp` can only hold pointer to `double`
  //int *ip = i;  // Error: a pointer can only hold address to object
  int *p = &i;  // OK

  return 0;
}
