// based on ex15.15
#include <string>
#include <iostream>

class Quote {
public:
  Quote() = default;
  Quote(const std::string &book, double pri)
      : bookNo(book), price(pri) { }

  virtual ~Quote() = default;

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }

  virtual std::ostream &debug(std::ostream &os) const {
    os << "Quote::bookNo " << bookNo << " Quote::price " << price;
    return os;
  }

protected:
  double price = 0.0;

private:
  std::string bookNo;
};

class Disc_quote : public Quote {
public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double pri,
             std::size_t qty, double disc)
      : Quote(book, pri), quantity(qty), discount(disc) { }

  double net_price(std::size_t n) const = 0;

  std::ostream &debug(std::ostream &os) const override {
    Quote::debug(os) << " Disc_quote::quantity " << quantity
        << " Disc_quote::discount " << discount;
    return os;
  }

protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double pri, std::size_t qty, double disc)
      : Disc_quote(book, pri, qty, disc) { }

  double net_price(std::size_t n) const override {
    if (n >= quantity)
      return n * price * (1 - discount);
    else
      return n * price;
  }
};

class Limit_quote : public Disc_quote {
public:
  Limit_quote() = default;
  Limit_quote(const std::string &book, double pri, std::size_t qty, double disc)
      : Disc_quote(book, pri, qty, disc) { }

  double net_price(std::size_t n) const override {
    if (n <= quantity)
      return n * price * (1 - discount);
    else
      return (n - quantity) * price + quantity * price * (1 - discount);
  }
};

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}

int main() {
  Disc_quote disc("abc", 5.5, 10, 0.2);  // Error, instantiate abstract class

  return 0;
}
