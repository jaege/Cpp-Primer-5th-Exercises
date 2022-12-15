// based on ex14.45 and ex16.2
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>

template <typename T>
int compare(const T &v1, const T&v2) {
  if (v1 < v2) return -1;
  if (v2 < v1) return 1;
  return 0;
}

/* Sales_data.h */
class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
  friend Sales_data operator+(const Sales_data &, const Sales_data &);
  friend std::istream &operator>>(std::istream &, Sales_data &);
  friend std::ostream &operator<<(std::ostream &, const Sales_data &);

public:
  Sales_data() : Sales_data("", 0, 0.0) {}
  explicit Sales_data(const std::string &no) : Sales_data(no, 0, 0.0) {}
  Sales_data(const std::string &no, unsigned us, double price)
      : bookNo(no), units_sold(us), revenue(price * us) {}
  explicit Sales_data(std::istream &is) : Sales_data() { read(is, *this); }

  Sales_data &operator+=(const Sales_data &);
  Sales_data &operator=(const std::string &);

  explicit operator std::string() const { return bookNo; }
  explicit operator double() const { return revenue; }

  std::string isbn() const { return bookNo; }

private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data operator+(const Sales_data &, const Sales_data &);
std::istream &operator>>(std::istream &, Sales_data &);
std::ostream &operator<<(std::ostream &, const Sales_data &);

inline
double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

/* Sales_data.cpp */
bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
  return sd1.isbn() < sd2.isbn();
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum += rhs;
  return sum;
}

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

Sales_data &Sales_data::operator=(const std::string &s) {
  bookNo = s;
  return *this;
}

/* Test.cpp */
int main(int argc, char **argv) {
  Sales_data s1("book1", 4, 2.5);
  Sales_data s2("book1", 10, 1.5);

  std::cout << compare(s1, s2) << std::endl;

  return 0;
}
