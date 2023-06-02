#include <iostream>
using namespace std;

static int rat_thing_power = 200;

void power_up_rat_thing(int nuclear_isotopes) {
  rat_thing_power += nuclear_isotopes;
  const auto waste_heat = rat_thing_power * 20;
  if (waste_heat > 9000) {
    std::cout << "IT'S OVER 9000!!!\n";
  }
}

int main() {
  for (int i = 0; i < 5; i++) {
    std::cout << "Rat thing power: " << rat_thing_power << "\n";
    power_up_rat_thing(i * 100);
  }
}