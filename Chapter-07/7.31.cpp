struct Y;

struct X {
  Y *y;
};

struct Y {
  X x;
};

int main() {
  return 0;
}
