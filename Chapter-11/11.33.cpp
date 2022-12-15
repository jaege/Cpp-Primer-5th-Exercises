#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

typedef std::map<std::string, std::string> trans_type;

trans_type build_map(std::istream &dict) {
  trans_type trans;
  std::string abbr, expr;
  while (dict >> abbr && std::getline(dict, expr))
    if (expr.size() > 1)
      trans[abbr] = expr.substr(1);
    else
      std::cerr << "Error: No rule for " << abbr << std::endl;
  return trans;
}

const std::string &transform(const std::string &s, const trans_type &trans) {
  auto it = trans.find(s);
  if (it != trans.end())
    return it->second;
  else
    return s;
}

void word_transform(std::istream &dict,
                    std::istream &in, std::ostream &out) {
  auto trans_map = build_map(dict);
  std::string line;
  while (std::getline(in, line)) {
    std::istringstream iss(line);
    std::string word;
    bool firstword = true;
    while (iss >> word) {
      if (firstword)
        firstword = false;
      else
        out << " ";
      out << transform(word, trans_map);
    }
    out << "\n";
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Useage: 11.33 <dict filename> [<input filename>] "
                 "[<output filename>]" << std::endl;
    return -1;
  }
  std::ifstream in_dict(argv[1]);
  if (!in_dict.is_open()) {
    std::cerr << "Cannot open file: " << argv[1] << std::endl;
    return -2;
  }
  std::ifstream in_text;
  if (argc >= 3) {
    in_text.open(argv[2]);
    if (!in_text.is_open()) {
      std::cerr << "Cannot open file: " << argv[2] << std::endl;
      return -2;
    }
  }
  std::istream &in = (argc >= 3 ? in_text : std::cin);
  std::ofstream out_text;
  if (argc >= 4) {
    out_text.open(argv[3]);
    if (!out_text.is_open()) {
      std::cerr << "Cannot open file: " << argv[3] << std::endl;
      return -2;
    }
  }
  std::ostream &out = (argc >= 4 ? out_text : std::cout);
  word_transform(in_dict, in, out);

  return 0;
}
