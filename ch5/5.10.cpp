#include <iostream>

int main() {
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
  char ch;
  while (std::cin >> ch) {
    switch(ch) {
      case 'A': case 'a':
        ++aCnt;
        break;
      case 'E': case 'e':
        ++eCnt;
        break;
      case 'I': case 'i':
        ++iCnt;
        break;
      case 'O': case 'o':
        ++oCnt;
        break;
      case 'U': case 'u':
        ++uCnt;
        break;
    }
  }
  std::cout << "Number of vowel a: " << aCnt << '\n'
            << "Number of vowel e: " << eCnt << '\n'
            << "Number of vowel i: " << iCnt << '\n'
            << "Number of vowel o: " << oCnt << '\n'
            << "Number of vowel u: " << uCnt << std::endl;

  return 0;
}
