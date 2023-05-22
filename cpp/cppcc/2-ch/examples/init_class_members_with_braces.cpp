#include <cstdio>

struct JohanVanDerSmut {
  ~JohanVanDerSmut() {
    printf("lutch mal diesen schwanz\n");
  }
  bool gold = true;
  int year_of_smelting_accident{ 1970 };
  char key_location[8]{ "x-rated" };
};

int main() {
  JohanVanDerSmut j;
  printf("The location of the key is %s.\n", j.key_location);
}