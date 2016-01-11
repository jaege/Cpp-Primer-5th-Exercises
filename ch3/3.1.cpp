#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;

void ex1_9() {
  int sum = 0, val = 50;
  while (val <= 100) {
    sum += val;
    ++val;
  }
  cout << "Sum of 50 to 100 inclusive is " << sum << endl;
}

void ex1_10() {
  int val = 10;
  while (val >= 0)
    cout << val-- << " ";
  cout << endl;
}

void ex1_11() {
  int bg = 0, ed = 0;
  cout << "Enter the number of begin and end: ";
  cin >> bg >> ed;
  while (bg <= ed)
    cout << bg++ << " ";
  cout << endl;
}

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

void ex1_20() {
  Sales_data item;
  double price = 0;
  while(cin >> item.bookNo >> item.units_sold >> price) {
    item.revenue = item.units_sold * price;
    cout << item.bookNo << " " << item.units_sold << " " << item.revenue << endl;
  }
}

int ex1_21(){
  Sales_data d1, d2;
  double price = 0;
  if (cin >> d1.bookNo >> d1.units_sold >> price) {
    d1.revenue = d1.units_sold * price;
    if (cin >> d2.bookNo >> d2.units_sold >> price) {
      d2.revenue = d2.units_sold * price;
      if (d1.bookNo == d2.bookNo) {
        unsigned totalSold = d1.units_sold + d2.units_sold;
        double totalRevenue = d1.revenue + d2.revenue;
        cout << d1.bookNo << " " << totalSold << " " << totalRevenue << " ";
        if (totalSold != 0)
          cout << totalRevenue / totalSold << endl;
        else
          cout << "(no sales)" << endl;
      } else {
        cerr << "Data must refer to the same ISBN!" << endl;
        return -1;
      }
    } else {
      cerr << "No data for item two!" << endl;
      return -1;
    }
  } else {
    cerr << "No data for item one!" << endl;
    return -1;
  }
  return 0;
}

int ex1_22(){
  Sales_data total, d;
  double price = 0;
  if (cin >> total.bookNo >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;
    while (cin >> d.bookNo >> d.units_sold >> price) {
      d.revenue = d.units_sold * price;
      if (total.bookNo == d.bookNo) {
        total.units_sold += d.units_sold;
        total.revenue += d.revenue;
      } else {
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
        if (total.units_sold != 0)
          cout << total.revenue / total.units_sold << endl;
        else
          cout << "(no sales)" << endl;
        total.bookNo = d.bookNo;
        total.units_sold = d.units_sold;
        total.revenue = d.revenue;
      }
    }
    cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
    if (total.units_sold != 0)
      cout << total.revenue / total.units_sold << endl;
    else
      cout << "(no sales)" << endl;
  } else {
    cerr << "No data for item!" << endl;
    return -1;
  }
  return 0;
}

int ex1_23(){
  Sales_data total, d;
  double price = 0;
  if (cin >> total.bookNo >> total.units_sold >> price) {
    int cnt = 1;
    while (cin >> d.bookNo >> d.units_sold >> price) {
      if (total.bookNo == d.bookNo) {
        ++cnt;
      } else {
        cout << total.bookNo << " " << cnt << endl;
        total.bookNo = d.bookNo;
        total.units_sold = d.units_sold;
        cnt = 1;
      }
    }
    cout << total.bookNo << " " << cnt << endl;
  } else {
    cerr << "No data for item!" << endl;
    return -1;
  }
  return 0;
}

void ex2_41() {
  //ex1_20();
  //ex1_21();
  //ex1_22();  // Also for ex1.25
  //ex1_23();  // Also for ex1.24
}

int main() {
  //ex1_9();
  //ex1_10();
  //ex1_11();
  //ex2_41();

  return 0;
}
