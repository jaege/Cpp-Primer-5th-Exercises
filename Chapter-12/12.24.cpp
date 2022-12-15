#include <iostream>

int main() {
  std::cout << "Input string length: ";
  size_t len;
  std::cin >> len;
  std::cin.ignore(); // ignore one char after the length number
  char *ca = new char[len + 1];
  std::cin.get(ca, len + 1);
  std::cout << "The input string is:\n\"" << ca << "\"" << std::endl;

  // If the input string is longer than the size of the array, then all input
  // characters whose positions are after the array size will be ignored.

  return 0;
}
