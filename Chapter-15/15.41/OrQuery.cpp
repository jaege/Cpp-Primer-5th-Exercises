#include "OrQuery.h"
#include <memory>  // make_shared
#include "TextQuery.h"
#include "QueryResult.h"

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

QueryResult OrQuery::eval(const TextQuery &t) const {
#if DEBUG_LEVEL >= 1
  std::cout << "OrQuery::eval" << std::endl;
#endif
  auto left = lhs.eval(t), right = rhs.eval(t);
  auto ret_lines =
      std::make_shared<std::set<line_no_type>>(left.cbegin(), left.cend());
  ret_lines->insert(right.cbegin(), right.cend());
  return QueryResult(rep(), ret_lines->size(), ret_lines, left.get_file());
}

Query operator|(const Query &lhs, const Query &rhs) {
#if DEBUG_LEVEL >= 1
  std::cout << "Query operator|(const Query &, const Query &)" << std::endl;
#endif
  //return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
  return new OrQuery(lhs, rhs);
}
