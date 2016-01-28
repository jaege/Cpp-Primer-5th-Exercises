#include <iostream>
#include <fstream>
#include "12.27\TextQuery.h"
#include "12.27\QueryResult.h"

void runQueries(std::ifstream &infile) {
  TextQuery tq(infile);
  do {
    std::cout << "Enter word to look for, or 'q' to exit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q")
      break;
    print(std::cout, tq.query(s)) << std::endl;
  } while (true);
}

int main() {
  std::cout << "Enter the file name to look up: ";
  std::string filename;
  std::cin >> filename;
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cerr << "Cannot open file: " << filename << std::endl;
    return -1;
  }
  runQueries(in);

  return 0;
}
