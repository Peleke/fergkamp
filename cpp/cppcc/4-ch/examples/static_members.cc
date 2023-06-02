#include <iostream>
using namespace std;

struct RatThing {
  static int rat_thing_power;
  static void power_up_rat_thing(int nuclear_isotopes) {
    rat_thing_power += nuclear_isotopes;
    const auto waste_heat = rat_thing_power * 20;

    std::cout << "Rat thing power: " << rat_thing_power << "\n";
    if (waste_heat > 9000) {
      std::cout << "IT'S OVER 9000!!!\n";
    }
  }
};

int RatThing::rat_thing_power = 200;

int main() {
  for (int i = 0; i < 5; i++) {
    RatThing::power_up_rat_thing(i * 100);
  }
}