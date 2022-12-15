#include <iostream>
#include "Sales_item.h"

int main() {
  Sales_item curItem, item;
  if (std::cin >> curItem) {
    int cnt = 1;
    while (std::cin >> item) {
      if (item.isbn() == curItem.isbn())
        ++cnt;
      else {
        std::cout << curItem.isbn() << " " << cnt << std::endl;
        curItem = item;
        cnt = 1;
      }
    }
    std::cout << curItem.isbn() << " " << cnt << std::endl;
  }

  return 0;
}
