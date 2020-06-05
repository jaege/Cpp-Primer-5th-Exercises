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
  if (maxCnt > 1) {
    std::cout << maxDuplicatedWord << " occurs " << maxCnt
              << " times." << std::endl;
  } else {
    std::cout << "No word was repeated." << std::endl;
  }
  return 0;
}
