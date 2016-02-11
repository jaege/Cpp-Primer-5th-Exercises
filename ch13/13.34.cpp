#include <string>
#include <set>

class Message {
  friend class Folder;
  friend void swap(Message &, Message &);
public:
  explicit Message(const std::string &s = "") : contents(s), folders() {}

  Message(const Message &);
  Message &operator=(const Message &);
  ~Message();

  void save(Folder &);
  void remove(Folder &);

private:
  std::string contents;
  std::set<Folder *> folders;

  void add_to_folders(const Message &);
  void remove_from_folders();
};

void swap(Message &, Message &);

class Folder {
  friend class Message;
  friend void swap(Message &, Message &);
public:

private:

  void addMsg(const Message *);
  void remMsg(const Message *);
};

void swap(Message &lhs, Message &rhs) {
  using std::swap;
  for (auto &fp : lhs.folders)
    fp->remMsg(&lhs);
  for (auto &fp : rhs.folders)
    fp->remMsg(&rhs);
  swap(lhs.contents, rhs.contents);
  swap(lhs.folders, rhs.folders);
  for (auto &fp : lhs.folders)
    fp->addMsg(&lhs);
  for (auto &fp : rhs.folders)
    fp->addMsg(&rhs);
}

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_folders(const Message &m) {
  // TODO could this function be without parameter?
  for (auto &fp : m.folders)
    fp->addMsg(this);
}

void Message::remove_from_folders() {
  for (auto &fp : folders)
    fp->remMsg(this);
  folders.clear();
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_folders(m);
}

Message &Message::operator=(const Message &rhs) {
  remove_from_folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_folders(rhs);
  return *this;
}

Message::~Message() {
  remove_from_folders();
}

void Folder::addMsg(const Message *mp) {
}

void Folder::remMsg(const Message *mp) {
}

int main() {
  return 0;
}
