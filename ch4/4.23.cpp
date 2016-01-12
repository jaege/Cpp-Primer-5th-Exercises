#include <string>
using std::string;

int main() {
  string s = "word";
  //string pl = s + s[s.size() - 1] == 's' ? "" : "s";
  string pl = s + (s[s.size() - 1] == 's' ? "" : "s");

  // The precedence of the conditional operator is lower than arithmetic operator.

  return 0;
}
