#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> text;

  std::string line;
  while (getline(std::cin, line))
    text.push_back(line);

  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    for (auto &c : *it)
      c = toupper(c);

  for (auto &elem : text)
    if (elem.empty())
      std::cout << std::endl;
    else
      std::cout << elem << " ";

  return 0;
}
