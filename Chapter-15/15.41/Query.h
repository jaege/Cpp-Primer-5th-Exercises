#ifndef QUERY_H
#define QUERY_H

class TextQuery;
class QueryResult;
class Query_base;

#include <memory>
#include <string>
#include <iostream>

class Query {
  friend Query operator~(const Query &);
  friend Query operator&(const Query &, const Query &);
  friend Query operator|(const Query &, const Query &);

public:
  Query(const std::string &);

  ~Query();
  Query(const Query &);
  Query &operator=(const Query &);
  //Query(Query &&);
  //Query &operator=(Query &&);

  QueryResult eval(const TextQuery &t) const;
  std::string rep() const;

private:
//  Query(std::shared_ptr<Query_base> query) : pq(query) {
//#if DEBUG_LEVEL >= 1
//    std::cout << "Query::Query(std::shared_ptr<Query_base>)" << std::endl;
//#endif
//  }

  // NOTE the pointer used in the following constructor must transfer the
  // ownership of the underlying object to this newly constructed object. Thus
  // an rvalue reference is used. Otherwise, that pointer (argument) may
  // become dangling pointer.
  Query(Query_base *&&query) : pq(query), ref_count(new std::size_t(1)) {
#if DEBUG_LEVEL >= 1
    std::cout << "Query::Query(Query_base *&&)" << std::endl;
#endif
    query = nullptr;
  }

  //std::shared_ptr<Query_base> pq;
  Query_base *pq;
  std::size_t *ref_count;
};

inline std::ostream &operator<<(std::ostream &os, const Query &q) {
  return os << q.rep();
}

#endif
