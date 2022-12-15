#include <vector>
#include <list>
#include <string>
#include <iostream>

int main() {
  std::vector<const char *> roster1{"abc", "def", "ghi"};
  std::list<const char *> roster2{"abc", "def", "ghi"};
  // Two C-style strings, compare the pointer (addresses of the two strings)
  std::cout << "The two sequences are "
            << (std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) ?
                "equal." : "not equal.") << std::endl;  // not equal

  // Two library strings, compare the value
  std::vector<std::string> roster3{"abc", "def", "ghi"};
  std::list<std::string> roster4{"abc", "def", "ghi"};
  std::cout << "The two sequences are "
            << (std::equal(roster3.cbegin(), roster3.cend(), roster4.cbegin()) ?
                "equal." : "not equal.") << std::endl;  // equal

  // One library string and one C-style string, compare the value
  std::cout << "The two sequences are "
            << (std::equal(roster1.cbegin(), roster1.cend(), roster4.cbegin()) ?
                "equal." : "not equal.") << std::endl;  // equal

  return 0;
}
