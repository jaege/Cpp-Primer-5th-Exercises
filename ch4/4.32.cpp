int main() {
  constexpr int size = 5;
  int ia[size] = {1, 2, 3, 4, 5};
  for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr) {
    /* some code */
  }

  // First, the loop created a pointer `ptr` point to the first element of the
  // array `ia` and an index `ix`.
  //
  // Then the loop will check if the index is at one past the last of the array
  // and if the pointer point to the element at one past the last of the array,
  // if these are not true, the loop continues.
  //
  // Every time, the index will increase 1 and the pointe will move to point
  // the next element.

  return 0;
}
