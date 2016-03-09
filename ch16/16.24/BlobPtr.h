#ifndef BLOBPTR_H
#define BLOBPTR_H

template <typename T> class BlobPtr;
template <typename T> bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> int operator-(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T> class Blob;

#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

// pointer-like type (iterator)
template <typename T>
class BlobPtr {
  friend bool operator==<T>(const BlobPtr &, const BlobPtr &);
  friend bool operator< <T>(const BlobPtr &, const BlobPtr &);  // note space
  friend int operator-<T>(const BlobPtr &, const BlobPtr &);

public:
  using size_type = typename std::vector<T>::size_type;

  BlobPtr() : wptr(), curr(0) { }

  explicit BlobPtr(Blob<T> &b, size_type pos = 0) : wptr(b.data), curr(0) {
    check(pos, "BlobPtr initial position out of range");
    curr = pos;
  }

  T &operator*() const {
    // dereference one-pass-end pointer is not allowed
    return (*check(curr + 1, "dereference out of range"))[curr];
  }

  T *operator->() const {
    return &**this;  // delegate by operator*
  }

  BlobPtr &operator++() {
    // check before change curr to keep class invariant
    check(curr + 1, "BlobPtr increament pass the end");
    ++curr;
    return *this;
  }

  BlobPtr operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
  }

  BlobPtr &operator--() {
    check(curr - 1, "BlobPtr decreament pass the beginning");
    --curr;
    return *this;
  }

  BlobPtr operator--(int) {
    BlobPtr ret = *this;
    --*this;
    return ret;
  }

  BlobPtr &operator+=(int n) {
    check(curr + n, "compound assignment out of range");
    curr += n;
    return *this;
  }

  BlobPtr &operator-=(int n) {
    return *this + -n;
  }

  BlobPtr operator+(int n) const {
    BlobPtr ret = *this;
    return ret += n;
  }

  BlobPtr operator-(int n) const {
    BlobPtr ret = *this;
    return ret += -n;
  }

private:
  std::weak_ptr<std::vector<T>> wptr;
  size_type curr;

  std::shared_ptr<std::vector<T>>
  check(size_type pos, const std::string &msg) const {
    std::shared_ptr<std::vector<T>> ret = wptr.lock();
    if (!ret)
      throw std::runtime_error("unbound BlobPtr");
    else if (pos > ret->size()) // [0, size], allow one-pass-end pointer
      throw std::out_of_range(msg);
    return ret;
  }
};

template <typename T>
int operator-(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
  return lhs.curr - rhs.curr;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
  // compare identity
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
  // compare identity
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
  return rhs < lhs;
}

template <typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
  return !(lhs > rhs);
}

template <typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
  return !(lhs < rhs);
}

using StrBlobPtr = BlobPtr<std::string>;

#endif
