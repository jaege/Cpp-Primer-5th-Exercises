// based on ex15.28
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <set>

#define DEBUG_LEVEL 1

class Quote {
public:
#if DEBUG_LEVEL == 2
  Quote() {
    std::cout << "Quote" << std::endl;
  }

  Quote(const std::string &book, double pri) : bookNo(book), price(pri) {
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
#else
  Quote() = default;
  Quote(const std::string &book, double pri) : bookNo(book), price(pri) { }

  virtual ~Quote() = default;
  Quote(const Quote &) = default;
  Quote(Quote &&) = default;
  Quote &operator=(const Quote &) = default;
  Quote &operator=(Quote &&) = default;
#endif

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }
  virtual Quote *clone() const & { return new Quote(*this); }
  virtual Quote *clone() && { return new Quote(std::move(*this)); }

#if DEBUG_LEVEL > 0
  virtual std::ostream &debug(std::ostream &os) const {
    os << "Quote::bookNo " << bookNo << " Quote::price " << price;
    return os;
  }
#endif

protected:
  double price = 0.0;

private:
  std::string bookNo;
};

class Disc_quote : public Quote {
public:
#if DEBUG_LEVEL == 2
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
#else
  Disc_quote() = default;
  Disc_quote(const std::string &book, double pri,
             std::size_t qty, double disc)
      : Quote(book, pri), quantity(qty), discount(disc) { }

  virtual ~Disc_quote() = default;
  Disc_quote(const Disc_quote &) = default;
  Disc_quote(Disc_quote &&) = default;
  Disc_quote &operator=(const Disc_quote &) = default;
  Disc_quote &operator=(Disc_quote &&) = default;
#endif

  double net_price(std::size_t n) const = 0;

#if DEBUG_LEVEL > 0
  std::ostream &debug(std::ostream &os) const override {
    Quote::debug(os) << " Disc_quote::quantity " << quantity
        << " Disc_quote::discount " << discount;
    return os;
  }
#endif

protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
  using Disc_quote::Disc_quote;

  double net_price(std::size_t n) const override {
    if (n >= quantity)
      return n * price * (1 - discount);
    else
      return n * price;
  }
  Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
  Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }
};

class Limit_quote : public Disc_quote {
public:
  using Disc_quote::Disc_quote;

  double net_price(std::size_t n) const override {
    if (n <= quantity)
      return n * price * (1 - discount);
    else
      return (n - quantity) * price + quantity * price * (1 - discount);
  }
  Limit_quote *clone() const & override { return new Limit_quote(*this); }
  Limit_quote *clone() && override { return new Limit_quote(std::move(*this)); }
};

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}

class Basket {
public:
  void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }
  void add_item(const Quote &sale) {
    items.insert(std::shared_ptr<Quote>(sale.clone()));
  }
  void add_item(Quote &&sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
  }

  double total_receipt(std::ostream &) const;

private:
  static bool compare(const std::shared_ptr<Quote> &lhs,
                      const std::shared_ptr<Quote> &rhs) {
    return lhs->isbn() < rhs->isbn();
  }

  std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double Basket::total_receipt(std::ostream &os) const {
  double sum = 0;
  for (auto it = items.cbegin(); it != items.cend();
       it = items.upper_bound(*it))
    sum += print_total(os, **it, items.count(*it));
  os << "Total sale: " << sum << std::endl;
  return sum;
}

void test_copy_control_members() {
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
}

int main() {
  //test_copy_control_members();

  std::vector<std::shared_ptr<Quote>> v;
  v.push_back(std::make_shared<Quote>("abc", 5.5));
  v.push_back(std::make_shared<Bulk_quote>("abc", 5.5, 10, 0.2));
  v.push_back(std::make_shared<Limit_quote>("abc", 5.5, 10, 0.2));

  for (const auto &q : v)
    print_total(std::cout, *q, 20);

  return 0;
}
