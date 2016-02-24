#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

class StrBlob;

#include <vector>
#include <string>
#include <memory>

class StrBlobPtr {
  friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlobPtr();
  explicit StrBlobPtr(StrBlob &sb, size_type pos = 0);

  // do not check range
  std::string &operator[](size_type n) { return (*wptr.lock())[n]; }
  const std::string &operator[](size_type n) const { return (*wptr.lock())[n]; }

  std::string &deref() const;
  //StrBlobPtr &inc();

  StrBlobPtr &operator++();
  StrBlobPtr operator++(int);
  StrBlobPtr &operator--();
  StrBlobPtr operator--(int);

private:
  std::weak_ptr<std::vector<std::string>> wptr;
  size_type curr;

  std::shared_ptr<std::vector<std::string>>
  check(size_type pos, const std::string &msg) const;
};

bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);
bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

#endif
