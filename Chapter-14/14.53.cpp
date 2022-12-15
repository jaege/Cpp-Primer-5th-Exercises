#include <iostream>

class SmallInt {
  friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
  SmallInt(int = 0) { } // conversion from int
  operator int() const { return val; } // conversion to int
private:
  std::size_t val;
};

SmallInt operator+(const SmallInt&, const SmallInt&) {
  std::cout << "operator+(const SmallInt&, const SmallInt&)" << std::endl;
  return SmallInt();
}

int main() {
  SmallInt s1;
  //double d = s1 + 3.14;  // Error
  // both `operator+(const SmallInt&, const SmallInt&)` and
  // `built-in operator+(int, double)` are viable functions

  double d = static_cast<double>(s1) + 3.14;  // OK
  // We can use `static_cast` convert `s1` from `SmallInt` to `double`

  double d2 = s1 + SmallInt(3.14);  // OK, but lose precision
  // Or use conversion constructor convert `3.14` from `double` to `SmallInt`

  return 0;
}
