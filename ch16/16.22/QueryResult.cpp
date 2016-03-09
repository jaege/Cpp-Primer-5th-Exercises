#include "QueryResult.h"

std::string make_plural(int cnt, const std::string &s,
                        const std::string &postfix = "s") {
  return cnt > 1 ? s + postfix : s;
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
  std::cout << "\"" << qr.word << "\" occurs " << qr.total << " "
            << make_plural(qr.total, "time") << ":\n";
  for (const auto &ln : *qr.line_numbers)
    std::cout << "(line " << ln + 1 << ") "
              << *(qr.line_text->begin() + ln) << std::endl;
  return os;
}
