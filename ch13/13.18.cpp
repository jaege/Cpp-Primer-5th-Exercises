#include <string>
#include <iostream>

class Employee {
public:
  typedef int id_type;
  Employee() : name(), id(++eid) {}
  explicit Employee(const std::string &n) : name(n), id(++eid) {}

  const std::string &getName() const { return name; }
  id_type getID() const { return id; }

private:
  std::string name;
  id_type id;
  static id_type eid;
};

Employee::id_type Employee::eid = 0;

int main() {
  Employee e1;
  Employee e2("Zhang San");

  std::cout << e1.getName() << " " << e1.getID() << std::endl;
  std::cout << e2.getName() << " " << e2.getID() << std::endl;

  return 0;
}
