#include <iostream>
#include "StrVec.h"

void print(const StrVec &sv) {
  std::cout << "<" << &sv << "> size: " << sv.size()
            << " capacity: " << sv.capacity() << " contents:";
  for (const auto &s : sv)
    std::cout << " <" << s << ">";
  std::cout << std::endl;
}

int main() {
  StrVec sv;
  print(sv);

  sv.push_back("s1"); print(sv);
  sv.push_back("s2"); print(sv);
  sv.push_back("s3"); print(sv);
  sv.push_back("s4"); print(sv);
  sv.push_back("s5"); print(sv);

  {
    StrVec sv2(sv); print(sv2);
    sv2.push_back("s6"); print(sv); print(sv2);
    sv.pop_back(); print(sv); print(sv2);
    sv = sv2; print(sv); print(sv2);
  }

  sv.reserve(sv.capacity() / 2); print(sv);
  sv.reserve(sv.capacity() * 2); print(sv);

  sv.resize(sv.size() + 2); print(sv);
  sv.resize(sv.size() + 2, "s7"); print(sv);
  sv.resize(sv.size() - 2); print(sv);
  sv.resize(sv.size() - 2, "s7"); print(sv);

  StrVec sv2 { "il1", "il2", "il3", "il4", "il5" }; print(sv2);
  StrVec sv3 = { "il1", "il2", "il3", "il4", "il5" }; print(sv3);

  return 0;
}
