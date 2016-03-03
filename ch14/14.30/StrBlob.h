#ifndef STRBLOB_H
#define STRBLOB_H

class StrBlobPtr;
class ConstStrBlobPtr;

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <iostream>

class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;
  friend bool operator==(const StrBlob &, const StrBlob &);
  friend bool operator!=(const StrBlob &, const StrBlob &);
  friend bool operator<(const StrBlob &, const StrBlob &);
  friend bool operator>(const StrBlob &, const StrBlob &);
  friend bool operator<=(const StrBlob &, const StrBlob &);
  friend bool operator>=(const StrBlob &, const StrBlob &);
public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlob();
  StrBlob(std::initializer_list<std::string> il);

  StrBlob(const StrBlob &);
  StrBlob &operator=(const StrBlob &);

  std::string &operator[](size_type n);
  const std::string &operator[](size_type n) const;

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  void push_back(const std::string &s);
  void push_back(std::string &&s);
  void pop_back();

  std::string &front();
  const std::string &front() const;
  std::string &back();
  const std::string &back() const;

  StrBlobPtr begin();
  StrBlobPtr end();

  ConstStrBlobPtr cbegin() const;
  ConstStrBlobPtr cend() const;

private:
  std::shared_ptr<std::vector<std::string>> data;

  void check(size_type pos, const std::string &msg) const;
};

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);

inline void StrBlob::push_back(const std::string &s) {
  data->push_back(s);
}

inline void StrBlob::push_back(std::string &&s) {
  std::cout << "StrBlob::push_back(std::string &&s)" << std::endl;
  data->push_back(std::move(s));
}

#endif
