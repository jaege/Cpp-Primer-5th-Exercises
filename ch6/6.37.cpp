#include <string>
using std::string;

string (&foo1())[10];

using arr_str_type = string[10];
//typedef string arr_str_type[10];
arr_str_type &foo2();

auto foo3() -> string (&)[10];

string str[10] = {};
decltype(str) &foo4();

// I prefer the trailing return form, because it's much easier to understand.
// I also prefer the type alias form, becasue it's easy to use, especially when
// the type being used many times.

string (&foo1())[10] {
  return str;
}

arr_str_type &foo2() {
  return str;
}

auto foo3() -> string (&)[10] {
  return str;
}

decltype(str) &foo4() {
  return str;
}

int main() {
  foo1();
  foo2();
  foo3();
  foo4();

  return 0;
}
