#include <ctime>
#include <iostream>
using namespace std;

struct TimerClass {
  const char* name;
  std::time_t timestamp;

  TimerClass(const char* name) : name { name } {
    timestamp = std::time(0);
  }
  TimerClass(const TimerClass& other)
    : timestamp { other.timestamp },
      name { other.name } { 
      //
  }
  TimerClass(TimerClass&& other) noexcept
  : name { other.name },
    timestamp { other.timestamp} {
      other.name = nullptr;
      other.timestamp = 0;
  }
  TimerClass& operator=(TimerClass&& other) noexcept {
    if (this == &other) return *this;
    delete[] name;
    name = other.name;
    timestamp = other.timestamp;
    other.name = nullptr;
    other.timestamp = 0;
    return *this;
  }
  TimerClass& operator=(const TimerClass& other) {
    if (this == &other) return *this;
    delete[] name;

    timestamp = other.timestamp;
    return *this;
  }
  ~TimerClass() {
    auto current = std::time(0);
    if (name == nullptr && timestamp == 0) {
      return;
    }
    printf("Timer %s elapsed: %f\n", this->name, current - this->timestamp);
  }
};

int main() {
  TimerClass timer{ "Timer1" };
  TimerClass timer2 = std::move(timer);
}