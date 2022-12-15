#include <string>
#include <vector>
#include <iostream>

// Use regular expression may be a better choice for this purpose.
// Also stringstream.
class Date {
  friend std::ostream &print(std::ostream &os, const Date &d);
public:
  explicit Date(const std::string &s);
  explicit Date(unsigned y = 0, unsigned m = 1, unsigned d = 1)
      : year(y), month(m), day(d) {}

private:
  unsigned year;
  unsigned month;
  unsigned day;
  static const std::vector<std::string> months;
  static const std::string alphabets;
};

const std::vector<std::string> Date::months{"Jan", "Feb", "Mar", "Apr", "May",
    "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

const std::string Date::alphabets{
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

Date::Date(const std::string &s) : Date() {
  if (s.find_first_of(alphabets) != std::string::npos) {
    // MMM dd yyyy  Dec 31, 1990    December 31, 1990
    for (std::vector<std::string>::size_type pos = 0;
        pos != months.size(); ++pos) {
      if (s.find(months[pos]) != std::string::npos) {
        month = pos + 1;
        break;
      }
    }
    std::string sub = s.substr(s.find_first_of("0123456789"));
    day = std::stoi(sub);
    sub = sub.substr(sub.find_first_not_of("0123456789"));
    sub = sub.substr(sub.find_first_of("0123456789"));
    year = std::stoi(sub);
  } else if (s.find_first_of('/') != std::string::npos) {
    // dd mm yyyy  31/12/1990
    std::string sub = s.substr(s.find_first_of("0123456789"));
    day = std::stoi(sub);
    sub = sub.substr(sub.find_first_not_of("0123456789"));
    sub = sub.substr(sub.find_first_of("0123456789"));
    month = std::stoi(sub);
    sub = sub.substr(sub.find_first_not_of("0123456789"));
    sub = sub.substr(sub.find_first_of("0123456789"));
    year = std::stoi(sub);
  } else {
    std::cerr << "Unrecognized date format." << std::endl;
  }
}

std::ostream &print(std::ostream &os, const Date &d) {
  os << "Year: " << d.year << " Month: " << d.month << " Day: " << d.day;
  return os;
}

void testDate(const std::string &s) {
  std::cout << s << "\n";
  print(std::cout, Date(s)) << std::endl;
}

int main() {
  std::cout << "Create from strings\n";
  testDate("December 10, 1990");
  testDate("10/12/1990");
  testDate("10 / 12 / 1990");
  testDate("10 12 1990");
  testDate("10??12++1990");
  testDate("Dec 10, 1990");
  testDate("  Dec 10 1990 ");

  std::cout << "\nCreate from numbers\n";
  print(std::cout, Date(1990)) << std::endl;
  print(std::cout, Date(1990, 12)) << std::endl;
  print(std::cout, Date(1990, 12, 10)) << std::endl;

  return 0;
}
