#include <vector>
using std::vector;

int main() {
  vector<int> v{1, 2, 3, 4, 5};

  auto begin = v.begin();
  while (begin != v.end()) {
    ++begin;
    begin = v.insert(begin, 42);
    //v.insert(begin, 42);
    // Iterator `begin` will become invalid after insert, thus if we don't
    // update the iterator, any usage of this iterator will have undefined
    // behaviours.
    ++begin;
  }

  return 0;
}
