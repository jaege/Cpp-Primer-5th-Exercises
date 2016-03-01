#ifndef TEXTQUERY_H
#define TEXTQUERY_H

class QueryResult;

#include <fstream>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "StrVec.h"

class TextQuery {
public:
  using line_no_type = StrVec::size_type;

  explicit TextQuery(std::ifstream &in);

  QueryResult query(const std::string &word) const;

private:
  std::string filter_str(const std::string &) const;
  std::shared_ptr<StrVec> text;
  std::map<std::string, std::shared_ptr<std::set<line_no_type>>> word_map;
};

#endif
