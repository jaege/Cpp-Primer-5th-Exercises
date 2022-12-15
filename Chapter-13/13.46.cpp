#include <vector>

int f() { return 0; }

int main() {
  std::vector<int> vi(100);

  int &&r1 = f();          // function that returns a nonreference type
  int &r2 = vi[0];         // subscript operator
  int &r3 = r1;            // variable
  int &&r4 = vi[0] * f();  // arithemtic operator

  return 0;
}
