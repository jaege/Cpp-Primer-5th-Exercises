#include <deque>
#include <iostream>
#include <string>

int main() {
  std::deque<std::string> words;
  std::string word;
  while (std::cin >> word)
    words.push_back(word);

  for (std::deque<std::string>::const_iterator it = words.cbegin();
       it != words.cend(); ++it)
    std::cout << *it << std::endl;

  return 0;
}
