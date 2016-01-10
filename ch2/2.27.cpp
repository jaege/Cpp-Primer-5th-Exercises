#include <iostream>

int main() {
  { //(a)
    //int i = -1, &r = 0;  // Error: a nonconst reference cannot be initialized to a literal
  }
  { //(b)
    int i2;
    int *const p2 = &i2;  // OK
  }
  { //(c)
    const int i = -1, &r = 0;  // OK
  }
  { //(d)
    int i2;
    const int *const p3 = &i2;  // OK
  }
  { //(e)
    int i2;
    const int *p1 = &i2;  // OK
  }
  { //(f)
    //const int &const r3;  // Error: 1. there is not top-level const for reference
                            //        2. a const reference must be initialized when defined
  }
  { //(g)
    int i;
    const int i2 = i, &r = i;  // OK, with a warning of using undefined variable `i`
    //r = 5;  // Error: cannot change the value of `i` through `r`
    std::cout << i << " " << i2 << " " << r << std::endl;  // Undefined Undefined Undefined Undefined
    i = 5;    // But the value can be changed directly
    std::cout << i << " " << i2 << " " << r << std::endl;  // 5  Undefined 5
    i = 10;   // And when visit through `r`, the new value is returned
    std::cout << i << " " << i2 << " " << r << std::endl;  // 10 Undefined 10
  }

  return 0;
}
