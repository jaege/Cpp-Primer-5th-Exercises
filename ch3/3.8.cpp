#include <iostream>
#include <string>

void change_with_while() {
  std::string s;
  if (std::cin >> s) {
    std::string::size_type pos = 0;  // also `decltype(s.size()) pos = 0`
    while (pos != s.size())
      s[pos++] = 'X';
  }
  std::cout << s << std::endl;
}

void change_with_for() {
  std::string s;
  if (std::cin >> s) {
    for (std::string::size_type pos = 0; pos != s.size(); ++pos)
      s[pos] = 'X';
  }
  std::cout << s << std::endl;
}

int main() {
  //change_with_while();
  //change_with_for();

  return 0;
}
