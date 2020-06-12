#include <string>
#include <iostream>
using std::string;
using std::ostream;

class base {
public:
  string name() { return basename; }
  virtual void print(ostream &os) { os << basename; }
private:
  string basename;
};

class derived : public base {
public:
  void print(ostream &os) { base::print(os); os << " " << i; }
private:
  int i = 0;
};

int main() {
  base bobj; base *bp1 = &bobj; base &br1 = bobj;
  derived dobj; base *bp2 = &dobj; base &br2 = dobj;
  // (a) base::print();
  bobj.print(std::cout);
  // (b) derived::print();
  dobj.print(std::cout);
  // (c) base::name();
  bp1->name();
  // (d) derived::name();
  bp2->name();
  // (e) base::print();
  br1.print(std::cout);
  // (f) derived::print();
  br2.print(std::cout);

  return 0;
}
