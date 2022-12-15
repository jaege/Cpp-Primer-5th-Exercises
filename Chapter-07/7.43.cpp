class NoDefault {
public:
  NoDefault(int i) : i_(i) {}
private:
  int i_;
};

class C {
public:
  C() : nd(0) {}

private:
  NoDefault nd;
};

int main() {
  C c;

  return 0;
}
