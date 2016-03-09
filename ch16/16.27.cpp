#include <string>
using std::string;

template <typename T> class Stack {
  typedef typename T::NotExist StaticAssert;  // used to test if instantiated
};
void f1(Stack<char>);                    // (a) not instantiate
class Exercise {
  Stack<double> &rsd;                    // (b) not instantiate
  //Stack<int> si;                       // (c) instantiate `Stack<int>`
};

int main() {
  Stack<char> *sc;                       // (d) not instantiate
  //f1(*sc);                             // (e) instantiate `Stack<char>`
  //int iObj = sizeof(Stack<string>);    // (f) instantiate `Stack<string>`
}

//void f1(Stack<char>) { }               // instantiate `Stack<char>`

// See [here](http://stackoverflow.com/q/21598635/5340808).
