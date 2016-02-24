#include "StrBlobPtr.h"
#include "StrBlob.h"

StrBlobPtr::StrBlobPtr() : wptr(), curr(0) {}
StrBlobPtr::StrBlobPtr(StrBlob &sb, size_type pos)
    : wptr(sb.data), curr(pos) {}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(size_type pos, const std::string &msg) const {
  auto ret = wptr.lock();
  if (!ret)
    throw std::runtime_error("unbound StrBlobPtr");
  if (pos >= ret->size())
    throw std::out_of_range(msg);
  return ret;
}

std::string &StrBlobPtr::deref() const {
  auto sp = check(curr, "deference past end of StrBlobPtr");
  return (*sp)[curr];
}

//StrBlobPtr &StrBlobPtr::inc() {
//  check(curr, "increment past end of StrBlobPtr");
//  ++curr;
//  return *this;
//}

StrBlobPtr &StrBlobPtr::operator++() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
  auto ret = *this;
  ++*this;
  return ret;
}

StrBlobPtr &StrBlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator--(int) {
  auto ret = *this;
  --*this;
  return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(int n) {  // uncheck range
  curr += n;
  return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(int n) {
  return *this += -n;
}

StrBlobPtr StrBlobPtr::operator+(int n) const {
  StrBlobPtr ret = *this;
  return ret += n;
}

StrBlobPtr StrBlobPtr::operator-(int n) const {
  StrBlobPtr ret = *this;
  return ret -= n;
}

int StrBlobPtr::operator-(const StrBlobPtr &rhs) const {
  return curr - rhs.curr;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  // compare identity
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return rhs < lhs;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs > rhs);
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs < rhs);
}
