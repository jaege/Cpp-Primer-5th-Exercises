#include <memory>

int main() {
  int ix = 1024, *pi = &ix, *pi2 = new int(2048);
  typedef std::unique_ptr<int> IntP;
  // (a) Illegal. `ix` is not a pointer.
  //IntP p0(ix);
  // (b) Illegal. The memory pointed by `p1` is not dynamically allocated in
  // heap, thus cannot be freed by a smart pointer.
  //IntP p1(pi);
  // (c) OK. Note that if `p2` is destoryed, `pi2` should not be use to visit
  // that memory any more.
  IntP p2(pi2);
  // (d) Illegal. Same reason as (b).
  //IntP p3(&ix);
  // (e) OK.
  IntP p4(new int(2048));
  // (f) Can be compiled, but will result error. Two unique pointers point to
  // the same memory, so that the memory will be freed twice when these
  // pointers are destoryed.
  //IntP p5(p2.get());

  return 0;
}
