class Base {
public:
  void pub_mem(); // public member
protected:
  int prot_mem; // protected member
private:
  char priv_mem; // private member
};

struct Pub_Derv : public Base {
  // ok: derived classes can access protected members
  int f() { return prot_mem; }
  // error: private members are inaccessible to derived classes
  //char g() { return priv_mem; }
};

struct Priv_Derv : private Base {
  // ok: private derivation doesn’t affect access in the derived class
  int f() { return prot_mem; }
  // error: private members are inaccessible to derived classes
  //char g() { return priv_mem; }
};

struct Prot_Derv : protected Base {
  // ok: derived classes can access protected members
  int f() { return prot_mem; }
  // error: private members are inaccessible to derived classes
  //char g() { return priv_mem; }
};

struct Derived_from_Public : public Pub_Derv {
  // ok: Base::prot_mem remains protected in Pub_Derv
  int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
  // error: Base::prot_mem is private in Priv_Derv
  //int use_base() { return prot_mem; }
};

struct Derived_from_Protected : public Prot_Derv {
  // ok: Base::prot_mem remains protected in Prot_Derv
  int use_base() { return prot_mem; }
};

int main() {
  Pub_Derv d1; Priv_Derv d2; Prot_Derv d3;
  Derived_from_Public dd1; Derived_from_Private dd2; Derived_from_Protected dd3;
  // Below are user code
  Base *p = &d1;  // legal
  p = &d2;        // illegal, user code may use the derived-to-base conversion
                  // only if D inherits publicly from B
  p = &d3;        // illegal, same reason as d2
  p = &dd1;       // legal
  p = &dd2;       // illegal, same reason as d2
  p = &dd3;       // illegal, same reason as d2

  return 0;
}
