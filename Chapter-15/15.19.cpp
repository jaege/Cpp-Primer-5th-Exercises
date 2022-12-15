// based on ex15.18
class Base {
public:
  void pub_mem(); // public member
protected:
  int prot_mem; // protected member
private:
  char priv_mem; // private member
};

struct Pub_Derv : public Base {
  // legal
  void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
  // legal
  void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
  // legal
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
  // legal
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
  // illegal
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv {
  // legal
  void memfcn(Base &b) { b = *this; }
};

int main() {
  return 0;
}
