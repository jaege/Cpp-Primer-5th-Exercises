#include <string>

int main() {
  int i = 0;
  double d = 0;
  std::string str("some string");
  const std::string *ps = &str;
  char c = 'c';
  char *pc = &c;
  void *pv;

  //pv = (void*)ps;
  pv = static_cast<void *>(const_cast<std::string *>(ps));
  //pv = const_cast<std::string *>(ps);  // Also work.

  //i = int(*pc);
  i = static_cast<int>(*pc);

  //pv = &d;
  pv = static_cast<void *>(&d);

  //pc = (char*) pv;
  pc = static_cast<char *>(pv);

  return 0;
}
