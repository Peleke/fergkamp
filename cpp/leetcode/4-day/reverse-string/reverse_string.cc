#include <iostream>
#include <vector>

void showVector(const std::vector<char> vec) {
  for (auto val : vec) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
}

void swapPosition(std::vector<char>& s, const int lo, const int hi) {
  int tmp = s[lo];
  s[lo] = s[hi];
  s[hi] = tmp;
}

void reverseString(std::vector<char>& s) {
  int lo = 0;
  int hi = s.size() - 1;

  while (lo < hi) {
    swapPosition(s, lo, hi);
    ++lo;
    --hi;
  }
}

int main() {
  std::vector<char> s{'s', 'a', 'l', 'v', 'e'};
  reverseString(s);
  showVector(s);
}