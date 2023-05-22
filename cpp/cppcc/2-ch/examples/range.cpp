#include <cstdio>

int main() {
  unsigned long maximum = 0;
  unsigned long values[] = {1, 10, 500, 67};

  for (unsigned long value : values) {
    if (value > maximum) {
      maximum = value;
    }
  }

  printf("Maximum is: %lu\n", maximum);
}