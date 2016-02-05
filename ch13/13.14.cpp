#include <iostream>
using std::cout; using std::endl;

class numbered {
public:
  numbered() : mysn(++sn) {}
  int mysn;
private:
  static int sn;
};

int numbered::sn = 0;

void f(numbered s) {
  cout << s.mysn << endl;
}

int main() {
  numbered a, b = a, c = b;
  f(a);  // 1
  f(b);  // 1
  f(c);  // 1
  numbered d;
  f(d);  // 2

  return 0;
}
