#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::cout << "All " << argc << " argument"
            << (argc > 1 ? "s are:" : " is:") << std::endl;
  for (int i = 0; i < argc; ++i)
    std::cout << i << "\t" << argv[i] << std::endl;

  return 0;
}
