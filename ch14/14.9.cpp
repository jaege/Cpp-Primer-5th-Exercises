#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

#define USE_OPERATOR

/* Sales_data.h */
class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
#ifndef USE_OPERATOR
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);
#else
  friend Sales_data operator+(const Sales_data &, const Sales_data &);
  friend std::istream &operator>>(std::istream &, Sales_data &);
  friend std::ostream &operator<<(std::ostream &, const Sales_data &);
#endif

public:
  Sales_data() : Sales_data("", 0, 0.0) {}
  explicit Sales_data(const std::string &no) : Sales_data(no, 0, 0.0) {}
  Sales_data(const std::string &no, unsigned us, double price)
      : bookNo(no), units_sold(us), revenue(price * us) {}
  explicit Sales_data(std::istream &is) : Sales_data() { read(is, *this); }

  Sales_data &combine(const Sales_data &);
#ifndef USE_OPERATOR
#else
  Sales_data &operator+=(const Sales_data &);
#endif

  std::string isbn() const { return bookNo; }

private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

#ifdef USE_OPERATOR
Sales_data operator+(const Sales_data &, const Sales_data &);
std::istream &operator>>(std::istream &, Sales_data &);
std::ostream &operator<<(std::ostream &, const Sales_data &);
#endif

inline
double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

/* Sales_data.cpp */
bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
  return sd1.isbn() < sd2.isbn();
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;  // Use default copy constructor
  sum.combine(rhs);
  return sum;
}

#ifndef USE_OPERATOR
std::istream &read(std::istream &is, Sales_data &item) {
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " "
     << item.revenue << " " << item.avg_price();
  return os;
}
#else
std::istream &operator>>(std::istream &is, Sales_data &item) {
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  if (is)
    item.revenue = item.units_sold * price;
  else
    item = Sales_data();
  return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " "
     << item.revenue << " " << item.avg_price();
  return os;
}
#endif

/* Test.cpp */
int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: 14.6 <input filename>" << std::endl;
    return -1;
  }
  std::ifstream in(argv[1]);
  if (!in) {
    std::cerr << "Fail to open file: " << argv[1] << std::endl;
    return -2;
  }
  std::vector<Sales_data> vsd;
#ifndef USE_OPERATOR
  for (Sales_data sd; read(in, sd); vsd.push_back(sd)) {}
#else
  for (Sales_data sd; in >> sd; vsd.push_back(sd)) {}
#endif
  std::cout << "Before sort:\n";
  for (const auto &sd : vsd)
#ifndef USE_OPERATOR
    print(std::cout, sd) << std::endl;
#else
    std::cout << sd << std::endl;
#endif
  std::sort(vsd.begin(), vsd.end(), compareIsbn);
  std::cout << "\nAfter sort:\n";
  for (const auto &sd : vsd)
#ifndef USE_OPERATOR
    print(std::cout, sd) << std::endl;
#else
    std::cout << sd << std::endl;
#endif

  return 0;
}
