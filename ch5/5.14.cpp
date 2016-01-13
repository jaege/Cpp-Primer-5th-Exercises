#include <iostream>
#include <string>

int main() {
  std::string word, duplicatedWord, maxDuplicatedWord;
  unsigned cnt = 0, maxCnt = 0;
  while (std::cin >> word) {
    if (word == duplicatedWord)
      ++cnt;
    else {
      if (cnt > maxCnt) {
        maxDuplicatedWord = duplicatedWord;
        maxCnt = cnt;
      }
      duplicatedWord = word;
      cnt = 1;
    }
  }
  if (cnt > maxCnt) {
    maxDuplicatedWord = duplicatedWord;
    maxCnt = cnt;
  }
  std::cout << maxDuplicatedWord << " occurs " << maxCnt
            << " time" << (maxCnt > 1 ? "s" : "") << ". " << std::endl;

  return 0;
}
