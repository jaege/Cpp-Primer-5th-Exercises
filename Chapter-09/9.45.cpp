#include <string>
#include <iostream>

std::string fixName(const std::string &name,
                    const std::string &prefix,
                    const std::string &postfix) {
  std::string newName = name;
  std::string pref = prefix + " ";
  newName.insert(newName.begin(), pref.begin(), pref.end());
  return newName.append(" " + postfix);
}

int main() {
  std::cout << fixName("James", "Mr.", "Jr.") << std::endl;

  std::string name, prefix, postfix;
  std::cin >> name >> prefix >> postfix;
  std::cout << fixName(name, prefix, postfix) << std::endl;

  return 0;
}
