#include <cstdio>

struct ClockOfTheLongNow {
  ClockOfTheLongNow(int year_in) {
    if (!set_year(year_in)) {
      year = 2023;
    }
  }
  ClockOfTheLongNow() {
    year = 2023;
  }
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
  ClockOfTheLongNow clock = ClockOfTheLongNow{ 2023 };
  ClockOfTheLongNow* clock_ptr = &clock;

  clock_ptr->add_year();

  printf("The year is %d.\n", clock_ptr->get_year());
}