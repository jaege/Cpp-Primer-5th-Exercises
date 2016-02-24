#include <iostream>

struct LongDouble {
  LongDouble(double = 0.0);
  operator double() {
    std::cout << "LongDouble::operator double()" << std::endl;
    return 0;
  }
  operator float() {
    std::cout << "LongDouble::operator float()" << std::endl;
    return 0;
  }
};
void calc(int) {
  std::cout << "void calc(int)" << std::endl;
}
void calc(LongDouble) {
  std::cout << "void calc(LongDouble)" << std::endl;
}

int main() {
  double dval = 0;
  calc(dval);
  // will call `void calc(int)`, since only standard conversion is used

  return 0;
}
