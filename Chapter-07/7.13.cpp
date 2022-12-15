#include <string>
#include <iostream>

struct Sales_data;
std::istream &read(std::istream &is, Sales_data &item);

struct Sales_data {
  Sales_data() = default;
  Sales_data(const std::string &no) : bookNo(no) {}
  Sales_data(const std::string &no, unsigned us, double price)
      : bookNo(no), units_sold(us), revenue(price * us) {}
  Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
  }

  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);

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
  os << item.isbn() << " " << item.units_sold << " " << item.revenue;
  return os;
}

int main() {
  Sales_data total(std::cin);
  //if (read(std::cin, total)) {
  if (std::cin) {
    Sales_data trans(std::cin);
    //while (read(std::cin, trans)) {
    while (std::cin) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(std::cout, total) << std::endl;
        total = trans;  // Use default copy constructor
      }
      read(std::cin, trans);  // Read new transaction
    }
    print(std::cout, total) << std::endl;
  } else {
    std::cerr << "No data!" << std::endl;
    return -1;
  }

  return 0;
}
