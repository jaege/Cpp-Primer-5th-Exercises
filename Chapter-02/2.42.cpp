#include <iostream>
#include "Sales_data.h"

void ex1_20() {
  Sales_data item;
  double price = 0;
  while(std::cin >> item.bookNo >> item.units_sold >> price) {
    item.revenue = item.units_sold * price;
    std::cout << item.bookNo << " " << item.units_sold << " " << item.revenue << std::endl;
  }
}

int ex1_21(){
  Sales_data d1, d2;
  double price = 0;
  if (std::cin >> d1.bookNo >> d1.units_sold >> price) {
    d1.revenue = d1.units_sold * price;
    if (std::cin >> d2.bookNo >> d2.units_sold >> price) {
      d2.revenue = d2.units_sold * price;
      if (d1.bookNo == d2.bookNo) {
        unsigned totalSold = d1.units_sold + d2.units_sold;
        double totalRevenue = d1.revenue + d2.revenue;
        std::cout << d1.bookNo << " " << totalSold << " " << totalRevenue << " ";
        if (totalSold != 0)
          std::cout << totalRevenue / totalSold << std::endl;
        else
          std::cout << "(no sales)" << std::endl;
      } else {
        std::cerr << "Data must refer to the same ISBN!" << std::endl;
        return -1;
      }
    } else {
      std::cerr << "No data for item two!" << std::endl;
      return -1;
    }
  } else {
    std::cerr << "No data for item one!" << std::endl;
    return -1;
  }
  return 0;
}

int ex1_22(){
  Sales_data total, d;
  double price = 0;
  if (std::cin >> total.bookNo >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;
    while (std::cin >> d.bookNo >> d.units_sold >> price) {
      d.revenue = d.units_sold * price;
      if (total.bookNo == d.bookNo) {
        total.units_sold += d.units_sold;
        total.revenue += d.revenue;
      } else {
        std::cout << total.bookNo << " "
                  << total.units_sold << " "
                  << total.revenue << " ";
        if (total.units_sold != 0)
          std::cout << total.revenue / total.units_sold << std::endl;
        else
          std::cout << "(no sales)" << std::endl;
        total.bookNo = d.bookNo;
        total.units_sold = d.units_sold;
        total.revenue = d.revenue;
      }
    }
    std::cout << total.bookNo << " "
              << total.units_sold << " "
              << total.revenue << " ";
    if (total.units_sold != 0)
      std::cout << total.revenue / total.units_sold << std::endl;
    else
      std::cout << "(no sales)" << std::endl;
  } else {
    std::cerr << "No data for item!" << std::endl;
    return -1;
  }
  return 0;
}

int ex1_23(){
  Sales_data total, d;
  double price = 0;
  if (std::cin >> total.bookNo >> total.units_sold >> price) {
    int cnt = 1;
    while (std::cin >> d.bookNo >> d.units_sold >> price) {
      if (total.bookNo == d.bookNo) {
        ++cnt;
      } else {
        std::cout << total.bookNo << " " << cnt << std::endl;
        total.bookNo = d.bookNo;
        total.units_sold = d.units_sold;
        cnt = 1;
      }
    }
    std::cout << total.bookNo << " " << cnt << std::endl;
  } else {
    std::cerr << "No data for item!" << std::endl;
    return -1;
  }
  return 0;
}

int main() {
  //ex1_20();
  //ex1_21();
  //ex1_22();  // Also for ex1.25
  //ex1_23();  // Also for ex1.24

  return 0;
}
