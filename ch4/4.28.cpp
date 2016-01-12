#include <iostream>

int main() {
  std::cout << "char        " << sizeof(char) << std::endl;
  std::cout << "wchar_t     " << sizeof(wchar_t) << std::endl;
  std::cout << "char16_t    " << sizeof(char16_t) << std::endl;
  std::cout << "char32_t    " << sizeof(char32_t) << std::endl;
  std::cout << "short       " << sizeof(short) << std::endl;
  std::cout << "int         " << sizeof(int) << std::endl;
  std::cout << "long        " << sizeof(long) << std::endl;
  std::cout << "long long   " << sizeof(long long) << std::endl;
  std::cout << "float       " << sizeof(float) << std::endl;
  std::cout << "double      " << sizeof(double) << std::endl;
  std::cout << "long double " << sizeof(long double) << std::endl;

  return 0;
}
