#ifndef NOTQUERY_H
#define NOTQUERY_H

class TextQuery;
class QueryResult;

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

#include <string>
#include <memory>
#include "Query.h"
#include "Query_base.h"

class NotQuery : public Query_base {
  friend Query operator~(const Query &);

  NotQuery(const Query &query) : q(query) {
#if DEBUG_LEVEL >= 1
  std::cout << "NotQuery::NotQuery(const Query &)" << std::endl;
#endif
  }

  QueryResult eval(const TextQuery &) const override;
  std::string rep() const override {
#if DEBUG_LEVEL >= 1
    std::cout << "NotQuery::rep" << std::endl;
#endif
    return "~(" + q.rep() + ")";
  }

  Query q;
};

// NOTE The `operator~` should not be `inline` here and should be put into
// seperate implementation file. Otherwise, we must include this header in all
// files where we want to use this operator. And since this header is not part
// of the interface, its a bad idea to have the user include this header in
// user code.
//inline Query operator~(const Query &q) {
//  return std::shared_ptr<Query_base>(new NotQuery(q));
//}
Query operator~(const Query &);

#endif
