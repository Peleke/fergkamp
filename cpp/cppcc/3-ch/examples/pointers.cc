#include <cstdio>

int main() {
  int gettysburg{};
  int* gettysburg_address = &gettysburg;
  *gettysburg_address = 17325;

  printf("Value at address: %d\n", *gettysburg_address);
  printf("Address: %p\n", &gettysburg);
  printf("Address: %p\n", gettysburg_address);
}