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

struct LongDouble {
  LongDouble(double = 0.0) { }

  operator double() {
    std::cout << "LongDouble::operator double()" << std::endl;
    return 0;
  }

  operator float() {
    std::cout << "LongDouble::operator float()" << std::endl;
    return 0;
  }

  LongDouble operator+(const SmallInt&) {
    std::cout << "LongDouble::operator+(const SmallInt&)" << std::endl;
    return *this;
  }
};

LongDouble operator+(LongDouble&, double) {
  std::cout << "operator+(LongDouble&, double)" << std::endl;
  return LongDouble();
}

int main() {
  SmallInt si;
  LongDouble ld;



  ld = si + ld;  // Error
  // candidate functions
  //   all built-in operator+
  //   LongDouble::operator+(const SmallInt&)
  //   operator+(LongDouble&, double)
  //   operator+(const SmallInt&, const SmallInt&)
  //
  // viable functions
  //   all built-in operator+
  //
  // best match function
  //   no best match function, all the following functions are equally good
  //   built-in operator+(int, double)
  //   built-in operator+(int, float)

  ld = ld + si;  // OK
  // candidate functions
  //   all build-in operator+
  //   LongDouble::operator+(const SmallInt&)
  //   operator+(LongDouble&, double)
  //   operator+(const SmallInt&, const SmallInt&)
  //
  // viable functions
  //   all build-in operator+
  //   LongDouble::operator+(const SmallInt&)
  //   operator+(LongDouble&, double)
  //
  // matched function
  //   LongDouble::operator+(const SmallInt&)

  return 0;
}
