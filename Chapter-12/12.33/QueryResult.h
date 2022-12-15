#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <string>
#include "StrBlob.h"

class QueryResult {
  friend std::ostream &print(std::ostream &os, const QueryResult &qr);
public:
  typedef StrBlob::size_type line_no_type;

  QueryResult(const std::string &wd,
              line_no_type t,
              std::shared_ptr<std::set<line_no_type>> lns,
              std::shared_ptr<StrBlob> lt)
      : word(wd), total(t), line_numbers(lns), line_text(lt) {}

  std::set<line_no_type>::iterator begin() { return line_numbers->begin(); }
  std::set<line_no_type>::iterator end() { return line_numbers->end(); }

  std::set<line_no_type>::const_iterator
  cbegin() const { return line_numbers->cbegin(); }

  std::set<line_no_type>::const_iterator
  cend() const { return line_numbers->cend(); }

  std::shared_ptr<StrBlob> get_file() { return line_text; }

private:
  std::string word;
  line_no_type total;
  std::shared_ptr<std::set<line_no_type>> line_numbers;
  std::shared_ptr<StrBlob> line_text;
};

std::ostream &print(std::ostream &os, const QueryResult &qr);

#endif
