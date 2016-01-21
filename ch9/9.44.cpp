#include <string>
#include <iostream>

void replaceStr(std::string &s,
                const std::string &oldVal,
                const std::string &newVal) {
  // Use `<` operator, because it is possible that `pos` jumps over the end
  for (std::string::size_type pos = 0; pos < s.size(); ) {
    if (s.substr(pos, oldVal.size()) == oldVal) {
        s.replace(pos, oldVal.size(), newVal);
        pos += newVal.size();
    } else
      ++pos;
  }
}

int main() {
  std::string s{"r u ok?\ngo thru\ntho tho altho\nthrough thruu"};

  std::cout << "Old:\n" << s << std::endl;
  replaceStr(s, "tho", "though");
  std::cout << "\nNew:\n" << s << std::endl;
  replaceStr(s, "thru", "through");
  std::cout << "\nNew:\n" << s << std::endl;
  replaceStr(s, "hl", "hello");
  std::cout << "\nNew:\n" << s << std::endl;
  replaceStr(s, "u", "you");
  std::cout << "\nNew:\n" << s << std::endl;

  return 0;
}
