#include "Query.h"
#include "WordQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_base.h"
#include "DebugDelete.h"

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

// NOTE The following member functions cannot be inline or they must be put
// into header, because they are used in different translation units.

//inline
Query::Query(const std::string &s) : pq(new WordQuery(s), DebugDelete()) {
#if DEBUG_LEVEL >= 1
  std::cout << "Query::Query(const std::string &)" << std::endl;
#endif
}

//inline
QueryResult Query::eval(const TextQuery &t) const {
#if DEBUG_LEVEL >= 1
  std::cout << "Query::eval" << std::endl;
#endif
  return pq->eval(t);
}

//inline
std::string Query::rep() const {
#if DEBUG_LEVEL >= 1
  std::cout << "Query::rep" << std::endl;
#endif
  return pq->rep();
}
