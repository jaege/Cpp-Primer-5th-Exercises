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

// NOTE The implementation must either be exposed so that virtual function
// calls could success, or be made that all classes who call these virtual
// functions as `friend`. Also note that even we call these virtual functions
// in members of class inherited from this class, `protected` is still not
// enough. That is because we use a `Query_base` pointer to call these virtual
// functions instead of `this` pointer.
friend class NotQuery; friend class BinaryQuery;  // Method 1
private:
//public:  // Method 2
  virtual QueryResult eval(const TextQuery &) const = 0;
  virtual std::string rep() const = 0;
};

#endif
