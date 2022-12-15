#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);

public:
  Sales_data() : Sales_data("", 0, 0.0) {}
  explicit Sales_data(const std::string &no) : Sales_data(no, 0, 0.0) {}
  Sales_data(const std::string &no, unsigned us, double price)
      : bookNo(no), units_sold(us), revenue(price * us) {}
  explicit Sales_data(std::istream &is) : Sales_data() { read(is, *this); }

  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);

private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

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

inline
double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: 10.17 <input filename>" << std::endl;
    return -1;
  }
  std::ifstream in(argv[1]);
  if (!in) {
    std::cerr << "Fail to open file: " << argv[1] << std::endl;
    return -2;
  }
  std::vector<Sales_data> vsd;
  for (Sales_data sd; read(in, sd); vsd.push_back(sd)) {}
  std::cout << "Before sort:\n";
  for (const auto &sd : vsd)
    print(std::cout, sd) << std::endl;
  std::sort(vsd.begin(), vsd.end(),
      [](const Sales_data &s1, const Sales_data &s2) {
        return s1.isbn() < s2.isbn();
      });
  std::cout << "\nAfter sort:\n";
  for (const auto &sd : vsd)
    print(std::cout, sd) << std::endl;

  return 0;
}
