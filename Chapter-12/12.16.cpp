#include <memory>

int main() {
  std::unique_ptr<int> p(new int(5));

  //std::unique_ptr<int> q(p);

  std::unique_ptr<int> q;
  //q = p;

  return 0;
}
