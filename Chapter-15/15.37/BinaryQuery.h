#ifndef BINARYQUERY_H
#define BINARYQUERY_H

class Query;  // Add

#if DEBUG_LEVEL >= 1
#include <iostream>
#endif

#include <string>
#include "Query_base.h"
//#include "Query.h"

class BinaryQuery : public Query_base {
protected:
//  BinaryQuery(const Query &l, const Query &r, const std::string &o)
//     : lhs(l), rhs(r), op(o) {
//#if DEBUG_LEVEL >= 1
//    std::cout << "BinaryQuery::BinaryQuery(const Query &, const Query &, "
//                 "const std::string &)" << std::endl;
//#endif
//  }
  BinaryQuery(std::shared_ptr<Query_base> pl, std::shared_ptr<Query_base> pr,
      const std::string &o) : plhs(pl), prhs(pr), op(o) {
#if DEBUG_LEVEL >= 1
    std::cout << "BinaryQuery::BinaryQuery(std::shared_ptr<Query_base>, "
                 "std::shared_ptr<Query_base>, "
                 "const std::string &)" << std::endl;
#endif
  }

  std::string rep() const override {
#if DEBUG_LEVEL >= 1
    std::cout << "BinaryQuery::rep" << std::endl;
#endif
    //return "(" + lhs.rep() + " " + op + " " + rhs.rep() + ")";
    return "(" + plhs->rep() + " " + op + " " + prhs->rep() + ")";
  }

  //Query lhs, rhs;
  std::shared_ptr<Query_base> plhs, prhs;
  std::string op;
};

#endif
