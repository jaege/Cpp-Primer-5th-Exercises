#include <string>
#include <iostream>

void findAllStr_v1(const std::string &s, const std::string &s2) {
  std::string::size_type pos = 0;
  while((pos = s.find_first_of(s2, pos)) != std::string::npos) {
    std::cout << "Find character " << s[pos] << " at " << pos << std::endl;
    ++pos;
  }
}

void findAllStr_v2(const std::string &s, const std::string &s2) {
  std::string::size_type lastpos = 0;
  std::string::size_type pos = 0;
  while((pos = s.find_first_not_of(s2, pos)) != std::string::npos) {
    for (auto i = lastpos; i != pos; ++i)
      std::cout << "Find character " << s[i] << " at " << i << std::endl;
    lastpos = ++pos;
  }
  for (auto i = lastpos; i != s.size(); ++i)
    std::cout << "Find character " << s[i] << " at " << i << std::endl;
}

void searchStr(const std::string &s) {
  const std::string numbers{"1234567890"};
  const std::string alphabets{"abcdefghijklmnopqrstuvwxyz"
                              "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  std::cout << "First version\n";
  std::cout << "Search string " << s << " for numeric characters:\n";
  findAllStr_v1(s, numbers);

  std::cout << "Search string " << s << " for alphabetic characters:\n";
  findAllStr_v1(s, alphabets);

  std::cout << "\nSecond version\n";
  std::cout << "Search string " << s << " for numeric characters:\n";
  findAllStr_v2(s, numbers);

  std::cout << "Search string " << s << " for alphabetic characters:\n";
  findAllStr_v2(s, alphabets);
}

int main() {
  std::string s{"ab2c3d7R4E6"};
  searchStr(s);
  std::cout << std::endl;

  std::cin >> s;
  searchStr(s);

  return 0;
}
