#include <vector>

int main() {
  //std::vector<int> vi{1, 2, 3, 4};
  std::vector<int> vi{2, 4};

  // If the container contains any odd values, the loop will continue
  // infinitely.
  auto iter = vi.begin();
  while (iter != vi.end()) { // The loop body should be a block.
    if (*iter % 2){
      iter = vi.insert(iter, *iter);
      ++iter;
    }
  ++iter; //Don't forget to increase the iterator for each loop.
  }
  return 0;
}
