#ifndef ORQUERY_H
#define ORQUERY_H

class TextQuery;
class QueryResult;

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

#include <string>
#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
  friend Query operator|(const Query &, const Query &);

  OrQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "|") {
#if DEBUG_LEVEL >= 1
    std::cout << "OrQuery::OrQuery(const Query &, const Query &)" << std::endl;
#endif
  }

  QueryResult eval(const TextQuery &) const override;
};

// NOTE The `operator|` should not be `inline` here and should be put into
// seperate implementation file. Otherwise, we must include this header in all
// files where we want to use this operator. And since this header is not part
// of the interface, its a bad idea to have the user include this header in
// user code.
//inline Query operator|(const Query &lhs, const Query &rhs) {
//  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
//}
Query operator|(const Query &, const Query &);

#endif
