#include <iostream>
#include <string>

void read_lines() {
  std::string line;
  while (getline(std::cin, line))
    std::cout << line << std::endl;
}

void read_words() {
  std::string word;
  while (std::cin >> word)
    std::cout << word << std::endl;
}

int main() {
  //read_lines();
  //read_words();

  return 0;
}
