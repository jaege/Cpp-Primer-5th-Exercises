int main() {
  // (a)
  'a';   // character literal, type is `char`
  L'a';  // wide character literal, type is `wchar_t`
  "a";   // character string literal
  L"a";  // wide character string literal

  // (b)
  10;    // integral literal, type is `int`
  10u;   // unsigned integral literal, type is `unsigned int`
  10L;   // integral literal, type is `long int`
  10uL;  // unsigned integral literal, type is `unsigned long int`
  012;   // octal integral literal, type is `int`
  0xC;   // hexadecimal integral literal, type is `int`

  // (c)
  3.14;   // floating-point literal, type is `double`
  3.14f;  // floating-point literal, type is `float`
  3.14L;  // floating-point literal, type is `long double`

  // (d)
  10;     // integral literal, type is `int`
  10u;    // unsigned integral literal, type is `unsigned int`
  10.;    // floating-point literal, type is `double`
  10e-2;  // floating-point literal, type is `double`

  return 0;
}
