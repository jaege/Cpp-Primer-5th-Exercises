#include <string>
#include <set>

/** Message.h **/

class Message {
  friend class Folder;
  friend void swap(Message &, Message &);
  friend void swap(Folder &, Folder &);
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

/** Folder.h **/

class Folder {
  friend class Message;
  friend void swap(Message &, Message &);
  friend void swap(Folder &, Folder &);
public:
  Folder() = default;

  Folder(const Folder &);
  Folder &operator=(const Folder &);
  ~Folder();

  void save(Message &);
  void remove(Message &);

private:
  std::set<Message *> messages;

  void addMsg(Message *);
  void remMsg(Message *);
};

void swap(Folder &, Folder &);

/** Message.cpp **/

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

/** Folder.cpp **/

void swap(Folder &lhs, Folder &rhs){
  using std::swap;
  for (auto &mp : lhs.messages)
    mp->folders.erase(&lhs);
  for (auto &mp : rhs.messages)
    mp->folders.erase(&rhs);
  swap(lhs.messages, rhs.messages);
  for (auto &mp : lhs.messages)
    mp->folders.insert(&lhs);
  for (auto &mp : rhs.messages)
    mp->folders.insert(&rhs);
}

void Folder::addMsg(Message *mp) {
  messages.insert(mp);
}

void Folder::remMsg(Message *mp) {
  messages.erase(mp);
}

void Folder::save(Message &m) {
  messages.insert(&m);
  m.folders.insert(this);
}

void Folder::remove(Message &m) {
  messages.erase(&m);
  m.folders.erase(this);
}

Folder::Folder(const Folder &f) : messages(f.messages) {
  for (auto &mp : messages)
    mp->folders.insert(this);
}

Folder &Folder::operator=(const Folder &rhs) {
  for (auto &mp : messages)
    mp->folders.erase(this);
  messages = rhs.messages;
  for (auto &mp : messages)
    mp->folders.insert(this);
  return *this;
}

Folder::~Folder() {
  for (auto &mp : messages)
    mp->folders.erase(this);
}

/** Test.cpp **/

int main() {
  Folder f1, f2;
  Message m1("Hello"), m2("World"), m3("Happy"), m4("New Year"), m5(":-)");

  f1.save(m1);
  f1.save(m2);
  f1.save(m5);

  f2.save(m3);
  f2.save(m4);
  f2.save(m5);

  return 0;
}
