int main() {
  int ival = 1.01;  // OK
  //int &rval1 = 1.01;  // Error: initializer must be `int` object
  int &rval2 = ival;  // OK
  //int &rval3;  // Error: a reference must be initialized when defined

  return 0;
}
