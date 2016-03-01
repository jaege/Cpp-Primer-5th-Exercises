#include "NotQuery.h"
#include <memory>  // make_shared
#include "TextQuery.h"
#include "QueryResult.h"

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

QueryResult NotQuery::eval(const TextQuery &t) const {
#if DEBUG_LEVEL >= 1
  std::cout << "NotQuery::eval" << std::endl;
#endif
  auto result = q.eval(t);
  auto ret_lines = std::make_shared<std::set<line_no_type>>();
  auto bg = result.cbegin(), ed = result.cend();
  auto sz = result.get_file()->size();
  for (std::size_t n = 0; n != sz; ++n) {
    if (bg == ed || *bg != n)
      ret_lines->insert(n);
    else if (bg != ed)
      ++bg;
  }
  return QueryResult(rep(), ret_lines->size(), ret_lines, result.get_file());
}

Query operator~(const Query &query) {
#if DEBUG_LEVEL >= 1
  std::cout << "Query operator~(const Query &)" << std::endl;
#endif
  //return std::shared_ptr<Query_base>(new NotQuery(query));
  return new NotQuery(query);
}
