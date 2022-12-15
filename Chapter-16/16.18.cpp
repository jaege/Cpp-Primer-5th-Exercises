// (a) every type parameter must be preceded by `typename` or `class`
//template <typename T, U, typename V> void f1(T, U, V);
template <typename T, typename U, typename V> void f1(T, U, V);

// (b) the function parameter name cannot be same as template parameter name
//template <typename T> T f2(int &T);
template <typename T> T f2(int &t);

// (c) the template parameter list should be first
//inline template <typename T> T foo(T, unsigned int*);
template <typename T> inline T foo(T, unsigned int*);

// (d) the function must have return type
//template <typename T> f4(T, T);
template <typename T> void f4(T, T);

// (e) no error, but the `typedef` will be hidden by template parameter name
typedef char Ctype;
template <typename Ctype> Ctype f5(Ctype a);

int main() {
  return 0;
}
