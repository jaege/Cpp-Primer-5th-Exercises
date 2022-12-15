#include <iostream>
#include <string>
#include <fstream>
#include "StrBlob.h"
#include "StrBlobPtr.h"

int main() {
  std::cout << "Input the file name: ";
  std::string filename;
  std::cin >> filename;
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cerr << "Cannot open file: " << filename << std::endl;
    return -1;
  }
  StrBlob texts;
  for (std::string line; std::getline(in, line); texts.push_back(line)) {}
  StrBlobPtr p = texts.begin();
  for (StrBlob::size_type pos = 0; pos != texts.size(); ++pos, p.inc())
    std::cout << pos + 1 << ":\t" << p.deref() << std::endl;
  // The following loop cannot be compiled, because we don't define the `!=`
  // operator for `StrBlobPtr`
  //for (StrBlobPtr p = texts.begin(); p != texts.end(); p.inc())

  return 0;
}
