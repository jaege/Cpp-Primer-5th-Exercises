#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>


int main(int argc, char**argv) {
  if (argc < 4) {
    std::cerr << "Usage: 10.33 <input filename> <odd number output filename> "
                 "<even number output filename>" << std::endl;
    return -1;
  }
  std::ifstream in(argv[1]);
  if (!in.is_open()) {
    std::cerr << "Cannot open file: " << argv[1] << std::endl;
    return -2;
  }
  std::ofstream out_odd(argv[2]), out_even(argv[3]);
  if (!out_odd.is_open()) {
    std::cerr << "Cannot open file: " << argv[2] << std::endl;
    return -2;
  }
  if (!out_even.is_open()) {
    std::cerr << "Cannot open file: " << argv[3] << std::endl;
    return -2;
  }
  std::istream_iterator<int> i_iter(in), eof;
  std::ostream_iterator<int> odd_iter(out_odd, " "), even_iter(out_even, "\n");
  std::for_each(i_iter, eof,
      [&](int i) { i % 2 ? odd_iter = i : even_iter = i; });

  return 0;
}
