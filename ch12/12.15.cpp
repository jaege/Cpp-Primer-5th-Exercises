#include <memory>
#include <iostream>

struct destination {
  unsigned id;
  explicit destination(unsigned des_id = 0) : id(des_id) {}
};  // resource

struct connection {
  destination *dest;
};

connection connect(destination *dest) {
  connection new_conn;
  new_conn.dest = dest;
  std::cout << "Setup connection to " << new_conn.dest->id << std::endl;
  return new_conn;
}

void disconnect(connection conn) {
  std::cout << "Stop connection to " << conn.dest->id << std::endl;
  //conn.dest = nullptr;
}

void f(destination &d) {
  connection c = connect(&d);
  std::shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
  // use connection
  std::cout << "Using connection " << c.dest->id << std::endl;
}

int main() {
  destination d(5);
  f(d);

  return 0;
}
