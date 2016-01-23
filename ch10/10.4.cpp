#include <numeric>
#include <vector>
#include <iostream>

int main() {
  std::vector<double> vi;
  for (double i; std::cin >> i; vi.push_back(i)) {}
  std::cout << "The sum of the sequence is "
            << std::accumulate(vi.cbegin(), vi.cend(), 0.0) << std::endl;
            //<< std::accumulate(vi.cbegin(), vi.cend(), 0) << std::endl;
  // The type of the third argument determines which + operator is used and is
  // the type that `accumulate` returns. The type of literal `0` is `int`, thus
  // we will lose all the decimals if we use `0`.

  return 0;
}
