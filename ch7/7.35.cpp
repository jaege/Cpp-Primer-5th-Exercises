#include <string>

typedef std::string Type;

Type initVal();  // std::string

class Exercise {
public:
  typedef double Type;
  Type setVal(Type);  // double setVal(double)
  Type initVal();  // double initVal()
private:
  int val;
};

Exercise::Type Exercise::setVal(Type parm) {  // double Exercise::setVal(double para)
//Type Exercise::setVal(Type parm) {  // Error: int Exercise::setVal(double para)
  val = parm + initVal();
  return val;
}

Exercise::Type Exercise::initVal() {
  return 0;
}

int main() {
  return 0;
}
