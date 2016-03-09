#include <sstream>
#include <cctype>  // ispunct, tolower
#include "TextQuery.h"
#include "QueryResult.h"
#include "DebugDelete.h"

std::string TextQuery::filter_str(const std::string &s) const {
  std::string ret;
  for (const auto &ch : s)
    if(!std::ispunct(ch))
      ret += std::tolower(ch);
  return ret;
}

TextQuery::TextQuery(std::ifstream &in)
    : text(new StrVec, DebugDelete()), word_map() {
  for (std::string line; std::getline(in, line); text->push_back(line)) {
    std::istringstream iss(line);
    for (std::string word; iss >> word; ) {
      auto &lns = word_map[filter_str(word)];
      if (!lns)
        lns.reset(new std::set<line_no_type>, DebugDelete());
      lns->insert(text->size());
    }
  }
}

QueryResult TextQuery::query(const std::string &word) const {
  static std::shared_ptr<std::set<line_no_type>>
      nodata(new std::set<line_no_type>, DebugDelete());
  auto filter_word = filter_str(word);
  auto it = word_map.find(filter_word);
  if (it == word_map.end())
    return QueryResult(word, 0, nodata, text);
  line_no_type total = 0;
  for (const auto &ln : *(it->second)) {
    std::istringstream iss(*(text->begin() + ln));
    for (std::string wd; iss >> wd; )
      if (filter_str(wd) == filter_word)
        ++total;
  }
  return QueryResult(word, total, it->second, text);
}
