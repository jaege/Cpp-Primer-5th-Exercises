int main() {
  //const int buf;       // Error: must be initialized
  int cnt = 0;         // OK
  const int sz = cnt;  // OK
  ++cnt;  // OK
  //++sz;   // Error: cannot change the value of a const variable

  return 0;
}
