#include <cstdio>

int abs(int x) {
  // Return absolute value of `x`.
  if (x < 0) {
    return -x;
  } else {
    return x;
  }
}

int main() {
  printf("abs(-1): %d\n", abs(-1));
  printf("abs(1): %d\n", abs(1));
}