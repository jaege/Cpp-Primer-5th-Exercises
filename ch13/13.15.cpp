#include <iostream>
using std::cout; using std::endl;

class numbered {
public:
  numbered() : mysn(++sn) {}
  numbered(const numbered &) : mysn(++sn) {}
  int mysn;
private:
  static int sn;
};

int numbered::sn = 0;

void f(numbered s) {
  // `s` is copy initialized from argument, thus `s.mysn` is not the same with
  // the argument we passed in.
  cout << s.mysn << endl;
}

int main() {
  numbered a, b = a, c = b;  // a.mysn = 1, b.mysn = 2, c.mysn = 3
  f(a);  // 4
  f(b);  // 5
  f(c);  // 6
  numbered d;
  f(d);  // 8

  return 0;
}
