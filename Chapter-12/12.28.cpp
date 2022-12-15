#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>

typedef std::vector<std::string>::size_type sz_type;

void runQueries(std::ifstream &infile);

std::string make_plural(int cnt, const std::string &s,
                        const std::string &postfix = "s") {
  return cnt > 1 ? s + postfix : s;
}

int main() {
  std::cout << "Enter the file name to look up: ";
  std::string filename;
  std::cin >> filename;
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cerr << "Cannot open file: " << filename << std::endl;
    return -1;
  }
  runQueries(in);

  return 0;
}

void init_text(std::ifstream &infile,
    std::vector<std::string> &text,
    std::map<std::string, std::set<sz_type>> &ln_maps);

void runQueries(std::ifstream &infile) {
  std::vector<std::string> text;
  std::map<std::string, std::set<sz_type>> ln_maps;
  // initialize from input file
  init_text(infile, text, ln_maps);
  while (true) {
    std::cout << "Enter word to look for, or 'q' to exit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q")
      break;
    // the following code combine query and print
    auto it = ln_maps.find(s);
    if (it == ln_maps.end()) {
      std::cout << "\"" << s << "\" occurs 0 time.\n" << std::endl;
      continue;
    }
    sz_type total = 0;
    for (const auto &ln : it->second) {
      std::istringstream iss(text[ln]);
      for (std::string wd; iss >> wd; )
        if (wd == s)
          ++total;
    }
    std::cout << "\"" << s << "\" occurs " << total << " "
              << make_plural(total, "time") << ":\n";
    for (const auto &ln : it->second)
      std::cout << "(line " << ln + 1 << ") " << text[ln] << std::endl;
    std::cout << std::endl;
  }
}

void init_text(std::ifstream &infile,
    std::vector<std::string> &text,
    std::map<std::string, std::set<sz_type>> &ln_maps) {
  sz_type ln = 0;
  for (std::string line; std::getline(infile, line);
      text.push_back(line), ++ln) {
    std::istringstream iss(line);
    for (std::string word; iss >> word; ln_maps[word].insert(ln)) {}
    //for (std::string word; iss >> word; ) {
    //  if(ln_maps.find(word) == ln_maps.end())
    //    ln_maps.insert({word, std::set<sz_type>()});
    //  ln_maps.at(word).insert(ln);
    //}
  }
}
