#include <stack>
#include <string>
#include <iostream>

// Currently, this program will only examine whether all parentheses are
// matched in expression and return a new expression that removed all
// parentheses, no calculation is carried out.

std::string calculateStr(const std::string &s);

std::string evalParenthesesExpression(const std::string &expression) {
  std::stack<char> stk;
  for (const auto &c : expression) {
    if (c == ')') {
      std::string str;
      while (!stk.empty() && stk.top() != '(') {
        str += stk.top();
        stk.pop();
      }
      if (stk.empty()) {
        std::cerr << "Error: parentheses not match in expression: "
                  << expression << std::endl;
        return "";
      }
      stk.pop();  // pop char `(`
      str = calculateStr(std::string(str.rbegin(), str.rend()));
      for (const auto &e : str)  // push back the result to stk
        stk.push(e);
    } else {
      stk.push(c);
    }
  }
  std::string str;
  while (!stk.empty()) {  // calculate what remains in stack
    if (stk.top() == '(') {
      std::cerr << "Error: parentheses not match in expression: "
                << expression << std::endl;
      return "";
    }
    str += stk.top();
    stk.pop();
  }
  str = calculateStr(std::string(str.rbegin(), str.rend()));
  return str;
}

// Calculate the expression without parentheses.
std::string calculateStr(const std::string &s) {
  // We can do the calculate here in future. The string passed in must not have
  // parentheses. Thus we only need to consider associativity and precedence of
  // the operators.
  // For now, just return the expression.
  return s;
}

int main() {
  std::cout << evalParenthesesExpression("12+34-56-((78-9)+10)") << std::endl;
  std::cout << evalParenthesesExpression("(12+34)-(56-((78-9)+10))") << std::endl;
  std::cout << evalParenthesesExpression("((12+34-(56-10)-1") << std::endl;
  std::cout << evalParenthesesExpression("12+34)-(56-10)-1") << std::endl;

  std::string expression;
  std::cin >> expression;
  std::cout << evalParenthesesExpression(expression) << std::endl;

  return 0;
}
