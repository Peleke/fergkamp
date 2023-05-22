#include <cstdio>

struct ClockOfTheLongNow {
  void add_year() {
    year++;
  }
  bool set_year(int new_year) {
    if (new_year < 2023) return false;
    year = new_year;
    return true;
  }
  int get_year() {
    return year;
  }
private:
  int year;
};

int main() {
  ClockOfTheLongNow clock;
  clock.set_year(2023);
  printf("The year is %d.\n", clock.get_year());

  clock.add_year();
  printf("The year will be %d.\n", clock.get_year());
}