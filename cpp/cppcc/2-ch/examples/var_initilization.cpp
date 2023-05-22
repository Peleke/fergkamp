#include <cstdio>

int main() {
  int a = 0;
  int b{};
  int c = {};
  int d;

  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);
  printf("d: %d\n", d);

  int e = 42;
  int f{ 42 };
  int g = { 42 };
  int h(42);

  printf("e: %d\n", e);
  printf("f: %d\n", f);
  printf("g: %d\n", g);
  printf("h: %d\n", h);
}