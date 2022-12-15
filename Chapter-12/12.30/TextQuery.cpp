#include <sstream>
#include "TextQuery.h"
#include "QueryResult.h"

TextQuery::TextQuery(std::ifstream &in)
    //: text(std::make_shared<std::vector<std::string>>()), word_map() {
    : text(new std::vector<std::string>), word_map() {
  //line_no_type ln = 0;
  for (std::string line; std::getline(in, line); text->push_back(line)) {  //, ++ln
    std::istringstream iss(line);
    for (std::string word; iss >> word; ) {
      //if (word_map.find(word) == word_map.end())
      //  word_map.insert({word, std::make_shared<std::set<line_no_type>>()});
      //word_map.at(word)->insert(ln);
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
    //return QueryResult(word);
    return QueryResult(word, 0, nodata, text);
  line_no_type total = 0;
  for (const auto &ln : *(it->second)) {
    std::istringstream iss((*text)[ln]);
    for (std::string wd; iss >> wd; )
      if (wd == word)
        ++total;
  }
  return QueryResult(word, total, it->second, text);
}
