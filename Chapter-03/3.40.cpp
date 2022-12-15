#include <iostream>

int main() {
  char s1[] = "Hello";
  char s2[] = "World";
  char s3[11];
  strcpy(s3, s1);
  strcat(s3, s2);
  std::cout << s3 << std::endl;

  return 0;
}
