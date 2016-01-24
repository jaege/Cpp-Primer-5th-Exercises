#include <map>
#include <string>
#include <iostream>

int main() {
  std::multimap<std::string, std::string> authors;

  authors.insert({"Zhang San", "Hello world 3"});
  authors.insert({"Zhang San", "Hello world"});
  authors.insert({"Wang Wu", "Hello again world 2"});
  authors.insert({"Zhang San", "Hello world 2"});
  authors.insert({"Li Si", "Bye world"});
  authors.insert({"Wang Wu", "Hello again world"});

  // Note that the key will be sorted alphabetically when inserted, but the
  // values with the same key will be kept their relative orders of their
  // insertions and cannot be sorted without other efforts.

  std::string name;
  do {
    std::cout << "All the books are:\n";
    for (const auto &pr : authors)
      std::cout << "Author: " << pr.first
                << "\tBook: " << pr.second << std::endl;

    std::cout << "\nEnter the author name you want delete: ";
    std::getline(std::cin, name);
    auto it = authors.find(name);
    if (it != authors.end())
      authors.erase(it);
    else
      std::cerr << "No author named \"" << name << "\", please try again!"
                << std::endl;
  } while (std::cin);

  return 0;
}
