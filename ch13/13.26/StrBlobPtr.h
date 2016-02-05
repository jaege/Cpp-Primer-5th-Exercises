#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

class StrBlob;

#include <vector>
#include <string>
#include <memory>

class StrBlobPtr {
public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlobPtr();
  explicit StrBlobPtr(StrBlob &sb, size_type pos = 0);

  std::string &deref() const;
  StrBlobPtr &inc();

private:
  std::weak_ptr<std::vector<std::string>> wptr;
  size_type curr;

  std::shared_ptr<std::vector<std::string>>
  check(size_type pos, const std::string &msg) const;
};

#endif
