#include <string>
#include <iostream>

std::string make_plural(size_t ctr, const std::string &word,
                        const std::string &ending = "s") {
  return (ctr > 1) ? word + ending : word;
}

int main() {
  std::cout << "success: " << make_plural(2, "success", "es") << std::endl;
  std::cout << "failure: " << make_plural(2, "failure") << std::endl;

  return 0;
}
