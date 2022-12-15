#include <string>
#include <iostream>

class Account {
  static constexpr int period = 30;
  friend std::ostream &print(std::ostream &, const Account &);

public:
  Account() : Account("", 0) {}
  //explicit Account(const std::string &o) : Account(o, 0.0) {}
  explicit Account(const std::string &o, double b = 0.0)
      : owner(o), balance(b), daily_tbl() {}

  void addInterest() { balance += balance * interestRate; }
  std::ostream &print(std::ostream &);

  static double rate() { return interestRate; }
  static void rate(double newRate) { interestRate = newRate; }

private:
  std::string owner;
  double balance;
  double daily_tbl[period];
  // If this statement is put after the initialization of `period`, then the
  // class will compile, otherwise, it will be an error. To solve the error, we
  // must define period before. Difining `period` outside class won't help.

  static double interestRate;
  static double initRate();
};

double Account::interestRate = initRate();

double Account::initRate() {
  return 0.1;
}

constexpr int Account::period;

std::ostream &print(std::ostream &os, const Account &a) {
  os << a.owner << " " << a.balance << "\n"
     << a.daily_tbl[0];
  return os;
}

int main() {
  Account act1;
  Account act2("Zhang San");
  Account act3("Li Si", 100.50);
  //Account act4 = "Wang";  // Error

  print(std::cout, act1) << std::endl;
  print(std::cout, act2) << std::endl;
  print(std::cout, act3) << std::endl;

  return 0;
}
