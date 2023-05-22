#include <cstdio>

int main() {
  char alphabet[27];
  for (int i = 0; i < 26; i++) {
    alphabet[i] = 97 + i;
  }
  alphabet[26] = 0;
  printf("lower: %s\n", alphabet);

  for (int i = 0; i < 26; i++) {
    alphabet[i] = 65 + i;
  }
  printf("upper: %s\n", alphabet);
}