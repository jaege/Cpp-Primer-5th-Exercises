// based on ex15.35

// Use diff tools to see the changes between this exercise and ex15.35. From
// the comparison, we should notice that just as user code is simplified by
// using the interface class, our own class code is also simplified by using
// the same interface class (at the cost of more function calls).

// Compile with parameter `/DDEBUG_LEVEL=1`(for Visual Studio) to enable print
// for ex15.36.
#include <iostream>
#include "Query.h"

//#include "BinaryQuery.h"
//#include "AndQuery.h"
//#include "OrQuery.h"

int main() {
  Query q = Query("fiery") & Query("bird") | Query("wind");
  std::cout << "==================" << std::endl;
  std::cout << q << std::endl;

  //BinaryQuery a = Query("fiery") & Query("bird");
  //AndQuery b = Query("fiery") & Query("bird");
  //OrQuery c = Query("fiery") & Query("bird");

  return 0;
}
