#include <iostream>

class IfThenElse {
public:
  typedef int value_type;
  value_type operator()(bool condition, value_type t, value_type f) const {
    return condition ? t : f;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::cout << IfThenElse()(n > 0, 1, -1) << std::endl;

  return 0;
}
