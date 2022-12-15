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

  const std::string &deref() const;
  ConstStrBlobPtr &inc();

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
