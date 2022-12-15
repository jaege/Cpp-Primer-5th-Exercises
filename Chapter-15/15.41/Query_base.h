#ifndef QUERY_BASE_H
#define QUERY_BASE_H

//class Query;  // No need forward declaration for only friend declaration
class QueryResult;

#include <string>
#include "TextQuery.h"

class Query_base {
  friend class Query;

protected:
  using line_no_type = TextQuery::line_no_type;
  virtual ~Query_base() = default;

private:
  virtual QueryResult eval(const TextQuery &) const = 0;
  virtual std::string rep() const = 0;
};

#endif
