#include <iostream>
#include <string>

void concatenate() {
  std::string total, s;
  while (std::cin >> s)
    total += s;
  std::cout << total;
}

void concatenate_with_space() {
  std::string total, s;
  if (std::cin >> total) {
    while (std::cin >> s)
      total += ' ' + s;
  }
  std::cout << total;
}

int main() {
  //concatenate();
  //concatenate_with_space();

  return 0;
}
