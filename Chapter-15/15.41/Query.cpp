#include "Query.h"
#include "WordQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_base.h"

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

Query::~Query() {
#if DEBUG_LEVEL >= 1
  std::cout << "Query::~Query()" << std::endl;
#endif
  if (--*ref_count == 0) {
    delete pq;
    delete ref_count;
  }
}

Query::Query(const Query &rhs)
    : pq(rhs.pq), ref_count(rhs.ref_count) {
#if DEBUG_LEVEL >= 1
  std::cout << "Query::Query(const Query &)" << std::endl;
#endif
  ++*ref_count;
}

Query &Query::operator=(const Query &rhs) {
#if DEBUG_LEVEL >= 1
  std::cout << "Query::operator=(const Query &)" << std::endl;
#endif
  if (this != &rhs) {
    if (--*ref_count == 0) {
      delete pq;
      delete ref_count;
    }
    pq = rhs.pq;
    ref_count = rhs.ref_count;
    ++*ref_count;
  }
  return *this;
}

//Query::Query(Query &&rhs) : pq(rhs.pq), ref_count(rhs.ref_count) {
//#if DEBUG_LEVEL >= 1
//  std::cout << "Query::Query(Query &&)" << std::endl;
//#endif
//  rhs.pq = nullptr;  // error?
//  rhs.ref_count = nullptr;
//}

//Query &Query::operator=(Query &&rhs) {
//#if DEBUG_LEVEL >= 1
//  std::cout << "Query::operator=(Query &&)" << std::endl;
//#endif
//  if (this != &rhs) {
//    if (--*ref_count == 0) {
//      delete pq;
//      delete ref_count;
//    }
//    pq = rhs.pq;
//    ref_count = rhs.ref_count;
//    rhs.pq = nullptr;  // error?
//    rhs.ref_count = nullptr;
//  }
//  return *this;
//}

// NOTE The following member functions cannot be inline or they must be put
// into header, because they are used in different translation units.

//inline
Query::Query(const std::string &s)
    : pq(new WordQuery(s)), ref_count(new std::size_t(1)) {
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
