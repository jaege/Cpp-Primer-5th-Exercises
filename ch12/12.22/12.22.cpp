#include <iostream>
#include "StrBlob.h"
#include "ConstStrBlobPtr.h"


void testStrBlob(const StrBlob &sb) {
  try {
    std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
  } catch (std::out_of_range err) {
    std::cerr << err.what() << " out of range" << std::endl;
  } catch (std::exception err) {
    std::cerr << err.what() << std::endl;
  }
}

void testConstStrBlobPtr(ConstStrBlobPtr &sbp) {
  try {
    //sbp.deref() = "Change";  // Error
    for (auto p = sbp; ; p.inc())
      std::cout << "deref: " << p.deref() << std::endl;
  } catch (std::out_of_range err) {
    std::cerr << err.what() << " out of range" << std::endl;
  } catch (std::exception err) {
    std::cerr << err.what() << std::endl;
  }
}

int main() {
  StrBlob sb1;

  StrBlob sb2{"Hello", "World"};

  const StrBlob csb1;
  testStrBlob(csb1);
  std::cout << std::endl;

  const StrBlob csb2{"This", "Blob"};
  testStrBlob(csb2);
  std::cout << std::endl;

  ConstStrBlobPtr csbp1;
  testConstStrBlobPtr(csbp1);
  std::cout << std::endl;

  ConstStrBlobPtr sbp2(sb1);
  testConstStrBlobPtr(sbp2);
  std::cout << std::endl;

  ConstStrBlobPtr sbp3(sb1, sb1.size());
  testConstStrBlobPtr(sbp3);
  std::cout << std::endl;

  ConstStrBlobPtr sbp4(sb2);
  testConstStrBlobPtr(sbp4);
  std::cout << std::endl;

  ConstStrBlobPtr sbp5(sb2, sb2.size());
  testConstStrBlobPtr(sbp5);
  std::cout << std::endl;

  ConstStrBlobPtr csbp2(csb1);
  testConstStrBlobPtr(csbp2);
  std::cout << std::endl;

  ConstStrBlobPtr csbp3(csb1, csb1.size());
  testConstStrBlobPtr(csbp3);
  std::cout << std::endl;

  ConstStrBlobPtr csbp4(csb2);
  testConstStrBlobPtr(csbp4);
  std::cout << std::endl;

  ConstStrBlobPtr csbp5(csb2, csb2.size());
  testConstStrBlobPtr(csbp5);
  std::cout << std::endl;
  return 0;
}
