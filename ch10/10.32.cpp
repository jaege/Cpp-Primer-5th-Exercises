#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iostream>
#include <fstream>
#include "Sales_item.h"

bool compareIsbn_v2(const Sales_item &sd1, const Sales_item &sd2) {
  return sd1.isbn() < sd2.isbn();
}

int process_transaction(std::istream &in, std::ostream &out) {
  Sales_item total;
  if (in >> total) {
    Sales_item trans;
    while (in >> trans) {
      if (total.isbn() == trans.isbn()) {
        total += trans;
      } else {
        out << total << std::endl;
        total = trans;  // Use default copy constructor
      }
    }
    out << total << std::endl;
  } else {
    std::cerr << "No data!" << std::endl;
    return -1;
  }
  return 0;
}

int process_transaction_v2(std::istream &in, std::ostream &out) {
  std::istream_iterator<Sales_item> i_iter(in), eof;
  std::vector<Sales_item> trans(i_iter, eof);
  if (trans.empty()) {
    std::cerr << "No data!" << std::endl;
    return -1;
  }
  sort(trans.begin(), trans.end(), compareIsbn_v2);
  // The original version in header use `==` operator, so that only
  // transactions having the same ISBN with the first transaction will be
  // sorted, others will be unsorted. This may not be what we want.
  std::ostream_iterator<Sales_item> o_iter(out, "\n");
  for (auto bg = trans.begin(), ed = bg; bg != trans.end(); bg = ed) {
    ed = std::find_if_not(bg, trans.end(),
        [bg](const Sales_item &i) { return i.isbn() == bg->isbn(); });
    o_iter = std::accumulate(bg, ed, Sales_item(bg->isbn()));
  }
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: 10.32 <input filename> [<output filename>]"
              << std::endl;
    return -3;
  }
  std::ifstream in(argv[1]);
  if (!in) {
    std::cerr << "Fail to open file: " << argv[1] << std::endl;
    return -2;
  }
  if (argc >= 3) {
    std::ofstream out(argv[2], std::ofstream::app);
    if (!out) {
      std::cerr << "Fail to open file: " << argv[1] << std::endl;
      return -2;
    }
    //process_transaction(in, out);
    process_transaction_v2(in, out);
  } else {
    //process_transaction(in, std::cout);
    process_transaction_v2(in, std::cout);
  }

  return 0;
}
