#include <iostream>
#include <vector>
#include <list>

struct X {
  X() { ++i; j = i; std::cout << "X() " << j << std::endl; }
  X(const X &) { ++i; j = i; std::cout << "X(const X &) " << j << std::endl; }
  X &operator=(const X &) { std::cout << "operator= " << j << std::endl; return *this; }
  ~X() { std::cout << "~X() " << j << std::endl; }
  static int i;
  int j;
};

int X::i = 0;

void f1(X x) {
}

void f2(X &x) {
}

X f3() {
  return X();
}

X f5() {
  X x;
  return x;
}

X &f4(X &x) {
  return x;
}

int main() {
  std::cout << "\n----- X x1;\n";
  X x1;
  std::cout << "\n----- f1(x1);\n";
  f1(x1);
  std::cout << "\n----- f2(x1);\n";
  f2(x1);
  std::cout << "\n----- X x3 = f3();\n";
  X x3 = f3();
  std::cout << "\n----- f3();\n";
  f3();
  std::cout << "\n----- X x5 = f5();\n";
  X x5 = f5();
  std::cout << "\n----- f5();\n";
  f5();
  std::cout << "\n----- X x4 = f4(x1);\n";
  X x4 = f4(x1);
  std::cout << "\n----- f4(x1);\n";
  f4(x1);
  std::cout << "\n----- X *x2 = new X;\n";
  X *x2 = new X;
  std::cout << "\n----- std::vector<X> vx;\n";
  std::vector<X> vx;
  std::cout << "\n----- vx.push_back(x1);\n";
  vx.push_back(x1);
  std::cout << "\n----- vx.push_back(*x2);\n";
  vx.push_back(*x2);  // The vector is reallocate here.
  std::cout << "\n----- std::list<X> vl;\n";
  std::list<X> vl;
  std::cout << "\n----- vl.push_back(x1);\n";
  vl.push_back(x1);
  std::cout << "\n----- vl.push_back(*x2);\n";
  vl.push_back(*x2);  // The list does not need reallocate.
  std::cout << "\n----- delete x2;\n";
  delete x2;
  std::cout << "\n----- \n";

  return 0;
}
