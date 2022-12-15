int main() {
  int month = 9, day = 7;      // OK
  int month1 = 09, day1 = 07;  // Error: the digit of octal integral literal should in range 0~7

  return 0;
}
