#include <string>
#include <iostream>
#include <fstream>

bool containAscenderOrDescender(const std::string &s) {
  // Upper case letters do not included.
  const std::string ascenders_and_descenders{"bdfghijklpqty"};
  return s.find_first_of(ascenders_and_descenders) != std::string::npos;
}

int main() {
  std::string filename;
  std::cin >> filename;
  std::ifstream in(filename);
  if (in.is_open()) {
    std::string longestWord, word;
    while (in >> word)
      if (!containAscenderOrDescender(word) && word.size() > longestWord.size())
        longestWord = word;
    if (longestWord.empty())
      std::cout << "There is no word contains neither ascenders nor descenders "
                   "in file \"" << filename << "\"." << std::endl;
    else
      std::cout << "The longest word that contains neither ascenders nor "
                   "descenders in file \"" << filename
                << "\" is \"" << longestWord << "\"." << std::endl;
  } else {
    std::cerr << "Can not open file: " << filename << std::endl;
  }

  return 0;
}
