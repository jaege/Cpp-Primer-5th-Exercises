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
    sv = std::move(sv2); print(sv); print(sv2);
  }

  sv.reserve(sv.capacity() / 2); print(sv);
  sv.reserve(sv.capacity() * 2); print(sv);

  sv.resize(sv.size() + 2); print(sv);
  sv.resize(sv.size() + 2, "s7"); print(sv);
  sv.resize(sv.size() - 2); print(sv);
  sv.resize(sv.size() - 2, "s7"); print(sv);

  StrVec sv2 { "il1", "il2", "il3", "il4", "il5" }; print(sv2);
  StrVec sv3 = { "il1", "il2", "il3", "il4", "il5" }; print(sv3);

  std::cout << (sv2 == sv3) << std::endl;  // true

  StrVec *p1 = &sv3, *p2 = &sv3;

  std::cout << (*p1 == *p2) << std::endl;  // true
  std::cout << std::endl;

  {
    StrVec vs1{"a", "b", "c"};
    StrVec vs2{"b", "b", "c"};
    StrVec vs3{"a", "b", "d"};
    StrVec vs4{"a", "b", "c", "a"};
    StrVec vs5{"a0", "b", "c"};
    StrVec vs6{"a", "c"};
    StrVec vs7{"a", "b", "c"};
    StrVec vs8{"a", "b"};
    std::cout << (vs1 < vs2) << std::endl;  // true
    std::cout << (vs1 < vs3) << std::endl;  // true
    std::cout << (vs1 < vs4) << std::endl;  // true
    std::cout << (vs1 < vs5) << std::endl;  // true
    std::cout << (vs1 < vs6) << std::endl;  // true
    std::cout << (vs1 < vs7) << std::endl;  // false
    std::cout << (vs1 < vs8) << std::endl;  // false

    std::cout << (vs1 > vs2) << std::endl;  // false
    std::cout << (vs1 > vs3) << std::endl;  // false
    std::cout << (vs1 > vs4) << std::endl;  // false
    std::cout << (vs1 > vs5) << std::endl;  // false
    std::cout << (vs1 > vs6) << std::endl;  // false
    std::cout << (vs1 > vs7) << std::endl;  // false
    std::cout << (vs1 > vs8) << std::endl;  // true
  }

  return 0;
}
