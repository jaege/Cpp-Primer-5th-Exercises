#include <functional>
#include <iostream>
#include <map>
#include <string>

int add(int a, int b) {
  return a + b;
}

struct multiple {
  int operator()(int a, int b) { return a * b; }
};

auto divide = [](int a, int b) { return a / b; };

int main() {
  std::map<std::string, std::function<int (int, int)>> ops = {
    { "+", add },
    { "-", std::minus<int>() },
    { "*", multiple() },
    { "/", divide },
    { "%", [](int a, int b) { return a % b; } }
  };

  int a, b;
  std::string op;
  do {
    std::cout << "Enter expression: ";
    std::cin >> a >> op >> b;
    auto it = ops.find(op);
    if (it != ops.end())
      std::cout << it->second(a, b) << std::endl;
    else
      std::cout << "Unrecognized operator: " << op << std::endl;
  } while (std::cin);

  return 0;
}
