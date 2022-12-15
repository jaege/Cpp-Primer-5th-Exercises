#include <iostream>
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"

void testStrBlob(StrBlob &sb) {
  try {
    sb.push_back("abc");
    std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
    sb.pop_back();
    std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
    sb.begin().deref() = "Change";
    for (auto p = sb.begin(); ; p.inc())
      std::cout << "deref: " << p.deref() << std::endl;
  } catch (std::out_of_range err) {
    std::cerr << err.what() << " out of range" << std::endl;
  } catch (std::exception err) {
    std::cerr << err.what() << std::endl;
  }
}

void testStrBlob(const StrBlob &sb) {
  try {
    std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
  } catch (std::out_of_range err) {
    std::cerr << err.what() << " out of range" << std::endl;
  } catch (std::exception err) {
    std::cerr << err.what() << std::endl;
  }
}

void testStrBlobPtr(StrBlobPtr &sbp) {
  try {
    sbp.deref() = "Change2";
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
  testStrBlob(sb1);
  std::cout << std::endl;

  StrBlob sb2{"Hello", "World"};
  testStrBlob(sb2);
  std::cout << std::endl;

  StrBlob sb3{"ABC", "DEF"};
  StrBlob sb4 = sb3;
  {
    std::cout << (sb3 == sb4 ? "equal" : "not equal") << std::endl;  // e
    StrBlobPtr sbp1(sb3), sbp2(sb4), sbp3(sb4), sbp4(sb4, sb4.size());
    std::cout << (sbp1 == sbp2 ? "equal" : "not equal") << std::endl;  // n
    std::cout << (sbp2 == sbp3 ? "equal" : "not equal") << std::endl;  // e
    std::cout << (sbp3 == sbp4 ? "equal" : "not equal") << std::endl;  // n
    ConstStrBlobPtr csbp1(sb3), csbp2(sb4), csbp3(sb4), csbp4(sb4, sb4.size());
    std::cout << (csbp1 == csbp2 ? "equal" : "not equal") << std::endl;  // n
    std::cout << (csbp2 == csbp3 ? "equal" : "not equal") << std::endl;  // e
    std::cout << (csbp3 == csbp4 ? "equal" : "not equal") << std::endl;  // n
    std::cout << std::endl;
  }
  sb4.push_back("GHI");
  testStrBlob(sb3);
  std::cout << std::endl;
  testStrBlob(sb4);
  std::cout << std::endl;

  const StrBlob csb1;
  testStrBlob(csb1);
  std::cout << std::endl;

  const StrBlob csb2{"This", "Blob"};
  testStrBlob(csb2);
  std::cout << std::endl;

  testStrBlob({"ppp", "qqq"});
  std::cout << std::endl;

  //testStrBlob({"mm", 1});  // Error

  StrBlobPtr sbp1;
  testStrBlobPtr(sbp1);
  std::cout << std::endl;

  StrBlobPtr sbp2(sb1);
  testStrBlobPtr(sbp2);
  std::cout << std::endl;

  StrBlobPtr sbp3(sb1, sb1.size());
  std::cout << (sbp3 == sbp2 ? "equal" : "not equal") << std::endl;  // e
  testStrBlobPtr(sbp3);
  std::cout << std::endl;

  StrBlobPtr sbp4(sb2);
  testStrBlobPtr(sbp4);
  std::cout << std::endl;

  StrBlobPtr sbp5(sb2, sb2.size());
  testStrBlobPtr(sbp5);
  std::cout << std::endl;

  return 0;
}
