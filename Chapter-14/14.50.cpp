struct LongDouble {
  LongDouble(double = 0.0);
  operator double();
  operator float();
};

int main() {
  LongDouble ldObj;
  int ex1 = ldObj;  // Error
  // Both convert to `double` and `float` are equally good match
  float ex2 = ldObj;  // OK
  // match `operator float`

  return 0;
}
