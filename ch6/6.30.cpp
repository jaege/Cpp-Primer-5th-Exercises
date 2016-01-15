#include <iostream>
#include <string>
using std::string;

bool str_subrange(const string &str1, const string &str2) {
  if (str1.size() == str2.size())
    return str1 == str2;
  auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
  for (decltype(size) i = 0; i != size; ++i) {
    if (str1[i] != str2[i])
      //return;  // Error: need a return value
      return false;
  }
  // Error: need a return statement
  return true;
}

int main() {
  string s1, s2;
  std::cin >> s1 >> s2;
  std::cout << str_subrange(s1, s2) << std::endl;

  return 0;
}
