#ifndef STRBLOB_H
#define STRBLOB_H

class StrBlobPtr;

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>

class StrBlob {
  friend class StrBlobPtr;
public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlob();
  StrBlob(std::initializer_list<std::string> il);

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  void push_back(const std::string &s);
  void pop_back();

  std::string &front();
  const std::string &front() const;
  std::string &back();
  const std::string &back() const;

  StrBlobPtr begin();
  StrBlobPtr end();

private:
  std::shared_ptr<std::vector<std::string>> data;

  void check(size_type pos, const std::string &msg) const;
};

inline void StrBlob::push_back(const std::string &s) {
  data->push_back(s);
}

#endif
