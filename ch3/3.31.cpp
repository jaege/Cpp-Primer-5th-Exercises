int main() {
  int ia[10];
  for (size_t i = 0; i != 10; ++i)
    ia[i] = i;

  // To get the size of an array one could use
  //     sz = sizeof(ia) / sizeof(*ia)
  // However, this will not work for some situations like dynamically allocated
  // array, pointer array, array in function parameter etc.

  return 0;
}
