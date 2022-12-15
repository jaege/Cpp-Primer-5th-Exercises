#include <memory>
using std::make_shared; using std::shared_ptr;

void process(shared_ptr<int> ptr) { }

int main() {
  auto p = new int();
  auto sp = make_shared<int>();

  // (a) OK. Initialize a shared pointer `ptr` inside function `process` as a
  // copy of `sp`, increase the reference count. After the function is
  // executed, destory `ptr` and decrease the reference count.
  process(sp);

  // (b) Error. Cannot implicitly convert a ordinary pointer to a smart pointer.
  //process(new int());

  // (c) Error. Cannot implicitly convert a ordinary pointer to a smart pointer.
  //process(p);

  // (d) Error. Initialize a shared pointer `ptr` inside function `process`
  // using ordinary pointer `p`, increase the reference count to 1. After the
  // function is executed, destory `ptr` and decrease the reference count to 0,
  // thus freed the memory pointed by `ptr`. However, the original ordianry
  // pointer `p` still points to that memory.
  //process(shared_ptr<int>(p));

  return 0;
}
