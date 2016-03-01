#include "AndQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

QueryResult AndQuery::eval(const TextQuery &t) const {
#if DEBUG_LEVEL >= 1
  std::cout << "AndQuery::eval" << std::endl;
#endif
  // TODO
  return QueryResult();
}

Query operator&(const Query &lhs, const Query &rhs) {
#if DEBUG_LEVEL >= 1
  std::cout << "Query operator&(const Query &, const Query &)" << std::endl;
#endif
  // NOTE we cannot use `std::make_shared` here, because the type of the
  // dynamically created object and the type of the object pointed by shared
  // pointer are different.
  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
