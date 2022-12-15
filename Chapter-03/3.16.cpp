#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

void print_vector_int(const vector<int> &v) {
  for (const auto & elem : v)
    std::cout << elem << " ";
  std::cout << std::endl;
}

void print_vector_string(const vector<string> &v) {
  for (const auto & elem : v)
    std::cout << elem << " ";
  std::cout << std::endl;
}

int main() {
  vector<int> v1;               // 0  element
  vector<int> v2(10);           // 10 elements, values are all 0
  vector<int> v3(10, 42);       // 10 elements, values are all 42
  vector<int> v4{10};           // 1  element,  value  is  10
  vector<int> v5{10, 42};       // 2  elements, values are 10 and 42
  vector<string> v6{10};        // 10 elements, values are all empty string
  vector<string> v7{10, "hi"};  // 10 elements, values are all "hi"

  print_vector_int(v1);
  print_vector_int(v2);
  print_vector_int(v3);
  print_vector_int(v4);
  print_vector_int(v5);
  print_vector_string(v6);
  print_vector_string(v7);

  return 0;
}
