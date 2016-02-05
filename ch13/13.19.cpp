// The Employee class need to define its own versions of the copy-control
// members, because we must ensure that the copyed object has different ID from
// the original object.

#include <string>
#include <iostream>

class Employee {
public:
  typedef int id_type;

  Employee() : name(), id(++eid) {}
  explicit Employee(const std::string &n) : name(n), id(++eid) {}
  Employee(const Employee &e) : name(e.name), id(++eid) {}

  Employee &operator=(const Employee &e);

  const std::string &getName() const { return name; }
  id_type getID() const { return id; }

private:
  std::string name;
  id_type id;
  static id_type eid;
};

Employee::id_type Employee::eid = 0;

Employee &Employee::operator=(const Employee &e) {
  name = e.name;
  //id = ++eid;  // keep the old id
  return *this;
}

int main() {
  Employee e1;
  std::cout << e1.getName() << " " << e1.getID() << std::endl;
  Employee e2("Zhang San");
  std::cout << e2.getName() << " " << e2.getID() << std::endl;
  Employee e3 = e2;
  std::cout << e3.getName() << " " << e3.getID() << std::endl;
  e1 = e2;
  std::cout << e1.getName() << " " << e1.getID() << std::endl;

  return 0;
}
