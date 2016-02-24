#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

class StrBlob;

#include <vector>
#include <string>
#include <memory>

class ConstStrBlobPtr {
  friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
public:
  typedef std::vector<std::string>::size_type size_type;

  ConstStrBlobPtr();
  explicit ConstStrBlobPtr(const StrBlob &sb, size_type pos = 0);

  // do not check range
  const std::string &operator[](size_type n) const { return (*wptr.lock())[n]; }

  //const std::string &deref() const;
  //ConstStrBlobPtr &inc();

  const std::string &operator*() const;
  const std::string *operator->() const;

  ConstStrBlobPtr &operator++();
  ConstStrBlobPtr operator++(int);
  ConstStrBlobPtr &operator--();
  ConstStrBlobPtr operator--(int);

  ConstStrBlobPtr &operator+=(int);
  ConstStrBlobPtr &operator-=(int);
  ConstStrBlobPtr operator+(int) const;
  ConstStrBlobPtr operator-(int) const;
  int operator-(const ConstStrBlobPtr &) const;

private:
  std::weak_ptr<std::vector<std::string>> wptr;
  size_type curr;

  std::shared_ptr<std::vector<std::string>>
  check(size_type pos, const std::string &msg) const;
};

bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

#endif
