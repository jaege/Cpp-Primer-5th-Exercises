#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <string>

class QueryResult {
  friend std::ostream &print(std::ostream &os, const QueryResult &qr);
public:
  typedef std::vector<std::string>::size_type line_no_type;
  //typedef TextQuery::line_no_type line_no_type;

  explicit QueryResult(const std::string &wd)
      : word(wd), total(0), line_numbers(), line_text() {}
  QueryResult(const std::string &wd,
              line_no_type t,
              std::shared_ptr<const std::set<line_no_type>> lns,
              std::shared_ptr<const std::vector<std::string>> lt)
      : word(wd), total(t), line_numbers(lns), line_text(lt) {}

private:
  std::string word;
  line_no_type total;
  std::shared_ptr<const std::set<line_no_type>> line_numbers;
  std::shared_ptr<const std::vector<std::string>> line_text;
};

std::ostream &print(std::ostream &os, const QueryResult &qr);

#endif
