#include <map>
#include <iostream>

int main() {
  std::map<int, int> mi;
  int a, b;
  while (std::cin >> a >> b) {
    auto it = mi.find(a);
    if (it != mi.end())
      it->second = b;
    else
      mi.insert({a, b});
  }
  for (auto it = mi.cbegin(); it != mi.cend(); ++it)
    std::cout << it->first << " : " << it->second << std::endl;

  return 0;
}
