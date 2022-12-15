#include <string>
#include <set>
#include <iostream>

/** Message.h **/

class Message {
  friend class Folder;
  friend void swap(Message &, Message &);
  friend void swap(Folder &, Folder &);
public:
  explicit Message(const std::string &s = "") : contents(s), folders() {}

  ~Message();
  Message(const Message &);
  Message &operator=(const Message &);
  Message(Message &&);
  Message &operator=(Message &&);

  void save(Folder &);
  void remove(Folder &);

  void print();

private:
  std::string contents;
  std::set<Folder *> folders;

  void add_to_folders(const Message &);
  void remove_from_folders();

  void addFdr(Folder *);
  void remFdr(Folder *);
};

void swap(Message &, Message &);

/** Folder.h **/

class Folder {
  friend class Message;
  friend void swap(Message &, Message &);
  friend void swap(Folder &, Folder &);
public:
  Folder() = default;

  ~Folder();
  Folder(const Folder &);
  Folder &operator=(const Folder &);

  void save(Message &);
  void remove(Message &);

  void print();

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

void Message::addFdr(Folder *fp) {
  folders.insert(fp);
}

void Message::remFdr(Folder *fp) {
  folders.erase(fp);
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
  // This function can be without parameter.
  for (auto &fp : m.folders)
    fp->addMsg(this);
}

void Message::remove_from_folders() {
  for (auto &fp : folders)
    fp->remMsg(this);
  folders.clear(); // This statement is not needed.
}

Message::~Message() {
  remove_from_folders();
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  std::cout << "Message::Message(const Message &m)" << std::endl;
  add_to_folders(m);
}

Message &Message::operator=(const Message &rhs) {
  std::cout << "Message::operator=(const Message &rhs)" << std::endl;
  remove_from_folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_folders(rhs);
  return *this;
}

Message::Message(Message &&rhs)
    : contents(std::move(rhs.contents)), folders(std::move(rhs.folders)) {
  std::cout << "Message::Message(Message &&rhs)" << std::endl;
  for (auto &fp : folders) {
    fp->remMsg(&rhs);
    fp->addMsg(this);
  }
  rhs.folders.clear();
}

Message &Message::operator=(Message &&rhs) {
  std::cout << "Message::operator=(Message &&rhs)" << std::endl;
  if (this != &rhs) {
    remove_from_folders();
    contents = std::move(rhs.contents);
    folders = std::move(rhs.folders);
    for (auto &fp : folders) {
      fp->remMsg(&rhs);
      fp->addMsg(this);
    }
    rhs.folders.clear();
  }
  return *this;
}

void Message::print() {
  std::cout << "Message <" << this << ">:<" << contents << "> in "
            << folders.size() << " folders:\n";
  for (const auto &fp : folders)
    std::cout << "\t<" << fp << ">\n";
}

/** Folder.cpp **/

void swap(Folder &lhs, Folder &rhs){
  using std::swap;
  for (auto &mp : lhs.messages)
    mp->remFdr(&lhs);
  for (auto &mp : rhs.messages)
    mp->remFdr(&rhs);
  swap(lhs.messages, rhs.messages);
  for (auto &mp : lhs.messages)
    mp->addFdr(&lhs);
  for (auto &mp : rhs.messages)
    mp->addFdr(&rhs);
}

void Folder::addMsg(Message *mp) {
  messages.insert(mp);
}

void Folder::remMsg(Message *mp) {
  messages.erase(mp);
}

void Folder::save(Message &m) {
  messages.insert(&m);
  m.addFdr(this);
}

void Folder::remove(Message &m) {
  messages.erase(&m);
  m.remFdr(this);
}

Folder::Folder(const Folder &f) : messages(f.messages) {
  for (auto &mp : messages)
    mp->addFdr(this);
}

Folder &Folder::operator=(const Folder &rhs) {
  for (auto &mp : messages)
    mp->remFdr(this);
  messages = rhs.messages;
  for (auto &mp : messages)
    mp->addFdr(this);
  return *this;
}

Folder::~Folder() {
  for (auto &mp : messages)
    mp->remFdr(this);
}

void Folder::print() {
  std::cout << "Folder <" << this << "> contains " << messages.size()
            << " messages:\n";
  for (const auto &mp : messages)
    std::cout << "\t<" << mp << ">:<" << mp->contents << ">\n";
}

/** Test.cpp **/

int main() {
  Folder f1, f2;
  Message m1("m1"), m2("m2"), m3("m3"), m4("m4"), m5("m5");

  std::cout << "\n===== Message save =====\n";
  m1.save(f1); m2.save(f1); m5.save(f1);
  m3.save(f2); m4.save(f2); m5.save(f2);
  f1.print(); f2.print(); std::cout << std::endl;
  m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

  {
    std::cout << "\n===== Message copy-constructor =====\n";
    Message m6(m5);
    f1.print(); f2.print(); std::cout << std::endl;
    m5.print(); m6.print();

    std::cout << "\n===== Message copy-assignment operator =====\n";
    m6 = m1;
    f1.print(); f2.print(); std::cout << std::endl;
    m5.print(); m6.print();

    std::cout << "\n===== Message move-constructor =====\n";
    Message m7(std::move(m6));
    f1.print(); f2.print(); std::cout << std::endl;
    m5.print(); m6.print(); m7.print();


    std::cout << "\n===== Message move-assignment operator =====\n";
    m6 = std::move(m7);
    f1.print(); f2.print(); std::cout << std::endl;
    m5.print(); m6.print(); m7.print();
  }
  std::cout << "\n===== Message destructor =====\n";
  f1.print(); f2.print(); std::cout << std::endl;
  m5.print();

  std::cout << "\n===== Message swap =====\n";
  swap(m1, m3);
  f1.print(); f2.print(); std::cout << std::endl;
  m1.print(); m3.print();
  swap(m1, m3);  // swap back

  std::cout << "\n===== Message swap self =====\n";
  swap(m1, m1);
  f1.print(); f2.print(); std::cout << std::endl;
  m1.print();

  std::cout << "\n===== Message remove =====\n";
  m1.remove(f1); m2.remove(f1); m5.remove(f1);
  m3.remove(f2); m4.remove(f2); m5.remove(f2);
  f1.print(); f2.print(); std::cout << std::endl;
  m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

  std::cout << "\n===== Folder save =====\n";
  f1.save(m1); f1.save(m2); f1.save(m5);
  f2.save(m3); f2.save(m4); f2.save(m5);
  f1.print(); f2.print(); std::cout << std::endl;
  m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

  {
    std::cout << "\n===== Folder copy-constructor =====\n";
    Folder f3(f1);
    f1.print(); f2.print(); f3.print(); std::cout << std::endl;
    m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

    std::cout << "\n===== Folder copy-assignment operator =====\n";
    f3 = f2;
    f1.print(); f2.print(); f3.print(); std::cout << std::endl;
    m1.print(); m2.print(); m3.print(); m4.print(); m5.print();
  }
  std::cout << "\n===== Folder destructor =====\n";
  f1.print(); f2.print(); std::cout << std::endl;
  m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

  std::cout << "\n===== Folder swap =====\n";
  swap(f1, f2);
  f1.print(); f2.print(); std::cout << std::endl;
  m1.print(); m2.print(); m3.print(); m4.print(); m5.print();
  swap(f1, f2);  // swap back

  std::cout << "\n===== Folder swap self =====\n";
  swap(f1, f1);
  f1.print(); f2.print(); std::cout << std::endl;
  m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

  std::cout << "\n===== Folder remove =====\n";
  f1.remove(m1); f1.remove(m2); f1.remove(m5);
  f2.remove(m3); f2.remove(m4); f2.remove(m5);
  f1.print(); f2.print(); std::cout << std::endl;
  m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

  return 0;
}
