#include <deque>
#include <list>     // 1. Include header
#include <iostream>
#include <string>

int main() {
  //std::deque<std::string> words;
  std::list<std::string> words;  // 2. Define variable
  std::string word;
  while (std::cin >> word)
    words.push_back(word);

  //for (std::deque<std::string>::const_iterator it = words.cbegin();
  // 3. Iterator. Note that if `auto` is used here, then nothing needs change.
  for (std::list<std::string>::const_iterator it = words.cbegin();
       it != words.cend(); ++it)
    std::cout << *it << std::endl;

  return 0;
}
