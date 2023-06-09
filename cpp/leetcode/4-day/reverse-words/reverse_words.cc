#include <iostream>

void swapPosition(std::string& s, int lo, int hi) {
    char tmp = s[lo];
    s[lo] = s[hi];
    s[hi] = tmp;
}

std::string reverseWord(std::string& s, int lo, int hi) {
    while (lo <= hi) {
        swapPosition(s, lo, hi);
        ++lo;
        --hi;
    }
    return s;
}

std::string reverseWords(std::string s) {
  int begindex = 0;
  for (int i = 0; i < s.size(); ++i) {
    // if we find a space, reverse words from beginning of word (`begindex`) up to space (`index - ``)
    if (s[i] == ' ') {
      reverseWord(s, begindex, i-1);
      begindex = i + 1;
    } else if (i == s.size() - 1) {
      // Perform same reversal at end of string
      reverseWord(s, begindex, i);
    }
  }
  return s;
}

int main() {
  std::string s = "salve, munde";
  std::string reversedWords = reverseWords(s);
  std::cout << reversedWords << "\n";
}