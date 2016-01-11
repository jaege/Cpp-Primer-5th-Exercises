int main() {
  constexpr size_t array_size = 10;
  int ia[array_size];  // index from `0` to `array_size - 1`
  //for (size_t ix = 1; ix <= array_size; ++ix)
  //  ia[ix] = ix;
  for (size_t ix = 0; ix < array_size; ++ix)
    ia[ix] = ix + 1;

  return 0;
}
