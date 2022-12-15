// based on ex15.35

// Compile with parameter `/DDEBUG_LEVEL=1`(for Visual Studio) to enable print
// for ex15.36.
#include <iostream>
#include <fstream>
#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"

void runQueries(std::ifstream &infile) {
  TextQuery tq(infile);

  Query q = Query("fiery") & Query("bird") | Query("wind");
  std::cout << "==================" << std::endl;
  std::cout << q << std::endl;
  std::cout << "==================" << std::endl;
  print(std::cout, q.eval(tq)) << std::endl;

  while (true) {
    std::cout << "Enter word to look for, or 'q' to exit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q")
      break;
    print(std::cout, tq.query(s)) << std::endl;
  }
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
