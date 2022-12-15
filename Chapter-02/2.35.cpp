int main() {
  const int i = 42;  // const int
  auto j = 1;  // int
  const auto &k = i;  // const int &
  auto *p = &i;  // const int *
  const auto j2 = i, &k2 = i;  // const int, const int &

  return 0;
}
