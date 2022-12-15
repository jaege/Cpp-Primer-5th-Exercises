#include <iostream>

int main() {
  constexpr size_t c_row = 3;
  constexpr size_t c_col = 4;
  int ia[c_row][c_col] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11}
  };

  for (const auto &row : ia) {
    for (const auto &col : row)
      std::cout << col << '\t';
    std::cout << std::endl;
  }

  for (size_t i = 0; i != c_row; ++i) {
    for (size_t j = 0; j != c_col; ++j)
      std::cout << ia[i][j] << '\t';
    std::cout << std::endl;
  }

  for (auto pr = ia; pr != ia + c_row; ++pr) {
    for (auto pc = *pr; pc != *pr + c_col; ++pc)
      std::cout << *pc << '\t';
    std::cout << std::endl;
  }

  return 0;
}
