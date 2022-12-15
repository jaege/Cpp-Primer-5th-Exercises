// based on ex15.15
#include <string>
#include <iostream>

class Quote {
public:
  Quote() {
    std::cout << "Quote" << std::endl;
  }

  Quote(const std::string &book, double pri)
      : bookNo(book), price(pri) {
    std::cout << "Quote(const std::string &book, double pri)" << std::endl;
  }

  virtual ~Quote() {
    std::cout << "~Quote" << std::endl;
  }
  Quote(const Quote &rhs) : price(rhs.price), bookNo(rhs.bookNo) {
    std::cout << "Quote(const Quote &rhs)" << std::endl;
  }
  Quote(Quote &&rhs) : price(std::move(rhs.price)),
                       bookNo(std::move(rhs.bookNo)) {
    std::cout << "Quote(Quote &&rhs)" << std::endl;
  }
  Quote &operator=(const Quote &rhs) {
    std::cout << "operator=(const Quote &rhs)" << std::endl;
    price = rhs.price;
    bookNo = rhs.bookNo;
    return *this;
  }
  Quote &operator=(Quote &&rhs) {
    std::cout << "operator=(Quote &&rhs)" << std::endl;
    price = std::move(rhs.price);
    bookNo = std::move(rhs.bookNo);
    return *this;
  }

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
  Disc_quote() {
    std::cout << "Disc_quote" << std::endl;
  }
  Disc_quote(const std::string &book, double pri,
             std::size_t qty, double disc)
      : Quote(book, pri), quantity(qty), discount(disc) {
    std::cout << "Disc_quote(const std::string &book, ... )" << std::endl;
  }

  ~Disc_quote() {
    std::cout << "~Disc_quote" << std::endl;
  }
  Disc_quote(const Disc_quote &rhs)
      : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {
    std::cout << "Disc_quote(const Disc_quote &rhs)" << std::endl;
  }
  Disc_quote(Disc_quote &&rhs) : Quote(std::move(rhs)),
                                 quantity(std::move(rhs.quantity)),
                                 discount(std::move(rhs.discount)) {
    std::cout << "Disc_quote(Disc_quote &&rhs)" << std::endl;
  }
  Disc_quote &operator=(const Disc_quote &rhs) {
    Quote::operator=(rhs);
    std::cout << "operator=(const Disc_quote &rhs)" << std::endl;
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
  }
  Disc_quote &operator=(Disc_quote &&rhs) {
    Quote::operator=(std::move(rhs));
    std::cout << "operator=(Disc_quote &&rhs)" << std::endl;
    quantity = std::move(rhs.quantity);
    discount = std::move(rhs.discount);
    return *this;
  }

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
  Quote basic0;
  basic0.debug(std::cout) << '\n' << std::endl;

  Quote basic1("abc", 5.5);
  basic1.debug(std::cout) << '\n' << std::endl;

  Quote basic2(basic1);
  basic2.debug(std::cout) << '\n' << std::endl;

  Quote basic3(std::move(basic2));
  basic3.debug(std::cout) << std::endl;
  basic2.debug(std::cout) << '\n' << std::endl;

  basic2 = basic3;
  basic2.debug(std::cout) << '\n' << std::endl;

  basic3 = std::move(basic1);
  basic3.debug(std::cout) << std::endl;
  basic1.debug(std::cout) << '\n' << std::endl;

  std::cout << "============================" << std::endl; 

  Bulk_quote bulk0;
  bulk0.debug(std::cout) << '\n' << std::endl;

  Bulk_quote bulk1("abc", 5.5, 10, 0.2);
  bulk1.debug(std::cout) << '\n' << std::endl;

  Bulk_quote bulk2(bulk1);
  bulk2.debug(std::cout) << '\n' << std::endl;

  Bulk_quote bulk3(std::move(bulk2));
  bulk3.debug(std::cout) << std::endl;
  bulk2.debug(std::cout) << '\n' << std::endl;

  bulk2 = bulk3;
  bulk2.debug(std::cout) << '\n' << std::endl;

  bulk3 = std::move(bulk1);
  bulk3.debug(std::cout) << std::endl;
  bulk1.debug(std::cout) << '\n' << std::endl;

  std::cout << "============================" << std::endl; 

  Limit_quote limit0;
  limit0.debug(std::cout) << '\n' << std::endl;

  Limit_quote limit1("abc", 5.5, 5, 0.1);
  limit1.debug(std::cout) << '\n' << std::endl;

  Limit_quote limit2(limit1);
  limit2.debug(std::cout) << '\n' << std::endl;

  Limit_quote limit3(std::move(limit2));
  limit3.debug(std::cout) << std::endl;
  limit2.debug(std::cout) << '\n' << std::endl;

  limit2 = limit3;
  limit2.debug(std::cout) << '\n' << std::endl;

  limit3 = std::move(limit1);
  limit3.debug(std::cout) << std::endl;
  limit1.debug(std::cout) << '\n' << std::endl;

  return 0;
}
