#ifndef BLOB_H
#define BLOB_H

template <typename T> class BlobPtr;
template <typename T> class ConstBlobPtr;

template <typename T> class Blob;
template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator<(const Blob<T> &, const Blob<T> &);

#include <vector>
#include <initializer_list>
#include <memory>
#include <string>
#include <stdexcept>

// value-like type
template <typename T>
class Blob {
  friend class BlobPtr<T>;
  friend class ConstBlobPtr<T>;

  friend bool operator==<T>(const Blob &, const Blob &);
  friend bool operator< <T>(const Blob &, const Blob &);  // note the space

public:
  using value_type = T;
  using size_type = typename std::vector<T>::size_type;

  using iterator = BlobPtr<T>;
  using const_iterator = ConstBlobPtr<T>;

  Blob() : data(std::make_shared<std::vector<T>>()) { }

  Blob(std::initializer_list<T> il)
      : data(std::make_shared<std::vector<T>>(il)) { }

  Blob(const Blob &rhs) : data(std::make_shared<std::vector<T>>(*rhs.data)) { }

  Blob &operator=(const Blob &rhs) {
    data = std::make_shared<std::vector<T>>(*rhs.data);
    return *this;
  }

  size_type size() const { return data->size(); }

  bool empty() const { return data->empty(); }

  void push_back(const T &t) { data->push_back(t); }

  void push_back(T &&t) { data->push_back(std::move(t)); }

  void pop_back() {
    check(0, "pop on empty Blob");
    data->pop_back();
  }

  const T &front() const {
    check(0, "front on empty Blob");
    return data->front();
  }

  T &front() {
    return const_cast<T &>(const_cast<const Blob &>(*this).front());
  }

  const T &back() const {
    check(0, "back on empty Blob");
    return data->back();
  }

  T &back() {
    return const_cast<T &>(const_cast<const Blob &>(*this).back());
  }

  const T &at(size_type pos) const {
    check(pos, "Blob subscript out of range");
    return (*data)[pos];
  }

  T &at(size_type pos) {
    return const_cast<T &>(const_cast<const Blob &>(*this).at(pos));
  }

  const T &operator[](size_type pos) const { return at(pos); }

  T &operator[](size_type pos) { return at(pos); }

  const_iterator begin() const { return const_iterator(*this); }

  iterator begin() { return iterator(*this); }

  const_iterator end() const { return const_iterator(*this, size()); }

  iterator end() { return iterator(*this, size()); }

  const_iterator cbegin() const { return begin(); }

  const_iterator cend() const { return end(); }

private:
  std::shared_ptr<std::vector<T>> data;

  void check(size_type pos, const std::string &msg) const {
    if (pos >= size())  // [0, size)
      throw std::out_of_range(msg);
  }
};

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
  return *lhs.data == *rhs.data;  // compare value
}

template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs) {
  return *lhs.data < *rhs.data;  // compare value
}

template <typename T>
bool operator>(const Blob<T> &lhs, const Blob<T> &rhs) {
  return rhs < lhs;
}

template <typename T>
bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs) {
  return !(lhs > rhs);
}

template <typename T>
bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs) {
  return !(lhs < rhs);
}

using StrBlob = Blob<std::string>;

#endif
