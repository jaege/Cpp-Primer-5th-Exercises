#include <string>

struct Person {
  std::string getName() const { return name; }
  std::string getAddress() const { return address; }

  std::string name;
  std::string address;
};

// The member function `getName` and `getAddress` should be `const`, because
// they don't change the object.

int main() {
  return 0;
}
