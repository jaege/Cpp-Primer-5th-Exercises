#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
using std::vector; using std::string; using std::cin; using std::cout;
using std::istringstream; using std::ostringstream; using std::endl;
using std::ifstream; using std::getline; using std::cerr;

struct PersonInfo {
  string name;
  vector<string> phones;
};

constexpr int kPhoneNumberLength = 11;

bool valid(const string &num) {
  if (num.size() != kPhoneNumberLength)
    return false;
  for (const auto &c : num)
    if (c < '0' || c > '9')
      return false;
  return true;
}

string format(const string &num) {
  return num.substr(0, 3) + '-' + num.substr(3, 4) + '-' + num.substr(7,4);
}

int main() {
  string filename;
  cin >> filename;
  ifstream in(filename);
  if (!in.is_open()) {
    std::cerr << "Fail to open file: " << filename << std::endl;
    return -1;
  }

  string line, word;
  vector<PersonInfo> people;
  while (getline(in, line)) {
    istringstream record(line);
    PersonInfo info;
    record >> info.name;
    while (record >> word)
      info.phones.push_back(word);
    people.push_back(info);
  }

  for (const auto &entry : people) {
    ostringstream formatted, badNums;
    for (const auto &nums : entry.phones) {
      if (!valid(nums)) {
        badNums << " " << nums;
      } else
        formatted << " " << format(nums);
    }
    if (badNums.str().empty())
      cout << entry.name << " " << formatted.str() << endl;
    else
      cerr << "input error: " << entry.name
           << " invalid number(s) " << badNums.str() << endl;
  }

  return 0;
}
