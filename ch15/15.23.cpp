#include <iostream>
using std::cout; using std::endl;

class Base {
public:
  virtual int fcn() { cout << "Base::fcn" << endl; return 0; }
};

class D1 : public Base {
public:
  //int fcn(int);
  int fcn() override {  // fixed by removing parameter and add keyword override
    cout << "D1::fcn" << endl; return 0;
  }
  virtual void f2() { cout << "D1::f2" << endl; }
};

class D2 : public D1 {
public:
  int fcn(int) { cout << "D2::fcn(int)" << endl; return 0; }
  int fcn() { cout << "D2::fcn" << endl; return 0; }
  void f2() { cout << "D2::f2" << endl; }
};

int main() {
  Base bobj; D1 d1obj; D2 d2obj;
  Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
  bp1->fcn(); // virtual call, will call Base::fcn at run time
  bp2->fcn(); // virtual call, will call D1::fcn at run time  <--- changed
  bp3->fcn(); // virtual call, will call D2::fcn at run time

  return 0;
}
