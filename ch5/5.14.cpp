#include <iostream>
#include <string>

int main() {

    std::string input, before, maxWord;
    unsigned max = 0, cnt = 0;

    while(std::cin >> input) {
        ++cnt;

        if (before != input) {
            if (max < cnt) {
                max = cnt;
                maxWord = before;
            }
            cnt = 0;
        }

        before = input;
    }

    if (!maxWord.empty())
        std::cout << maxWord << " occurred " << max << " times." << std::endl;
    else
        std::cout << "No duplicates" << std::endl;

    return 0;
}
