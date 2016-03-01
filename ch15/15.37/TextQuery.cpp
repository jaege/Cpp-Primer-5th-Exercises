#include <sstream>
#include "TextQuery.h"
#include "QueryResult.h"

TextQuery::TextQuery(std::ifstream &in)
    : text(new StrVec), word_map() {
  for (std::string line; std::getline(in, line); text->push_back(line)) {
    std::istringstream iss(line);
    for (std::string word; iss >> word; ) {
      auto &lns = word_map[word];
      if (!lns)
        lns.reset(new std::set<line_no_type>);
      lns->insert(text->size());
    }
  }
}

QueryResult TextQuery::query(const std::string &word) const {
  static std::shared_ptr<std::set<line_no_type>>
      nodata(new std::set<line_no_type>);
  auto it = word_map.find(word);
  if (it == word_map.end())
    return QueryResult(word, 0, nodata, text);
  line_no_type total = 0;
  for (const auto &ln : *(it->second)) {
    std::istringstream iss(*(text->begin() + ln));
    for (std::string wd; iss >> wd; )
      if (wd == word)
        ++total;
  }
  return QueryResult(word, total, it->second, text);
}
