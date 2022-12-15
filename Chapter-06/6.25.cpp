#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::cout << "All " << argc << " argument"
            << (argc > 1 ? "s are:" : " is:") << std::endl;
  for (int i = 0; i < argc; ++i)
    std::cout << i << "\t" << argv[i] << std::endl;
  if (argc < 3)  // programname argument1 argument2 0
    return -1;
  std::string args(argv[1]);
  args += argv[2];
  std::cout << args << std::endl;

  return 0;
}
