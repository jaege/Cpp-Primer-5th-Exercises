#include "OrQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query.h"  // Add

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

QueryResult OrQuery::eval(const TextQuery &t) const {
#if DEBUG_LEVEL >= 1
  std::cout << "OrQuery::eval" << std::endl;
#endif
  // TODO
  return QueryResult();
}

Query operator|(const Query &lhs, const Query &rhs) {
#if DEBUG_LEVEL >= 1
  std::cout << "Query operator|(const Query &, const Query &)" << std::endl;
#endif
  //return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
  return std::shared_ptr<Query_base>(new OrQuery(lhs.pq, rhs.pq));
}
