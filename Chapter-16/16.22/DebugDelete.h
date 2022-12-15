#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>

class DebugDelete {
public:
  DebugDelete(std::ostream &s = std::cerr) : os(s) { }

  template <typename T> void operator()(T *p) const {
    os << "deleting pointer " << typeid(p).name() << std::endl;
    delete p;
  }

private:
  std::ostream &os;
};

#endif
