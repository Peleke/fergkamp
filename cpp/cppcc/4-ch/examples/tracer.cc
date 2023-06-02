#include <iostream>
using namespace std;

struct Tracer {
  Tracer(const char* name) : name { name } {
    std::cout << name << " constructed.\n";
  }
  ~Tracer() {
    std::cout << name << " destructed.\n";
  }
private:
  const char* name;
};

static Tracer t1 { "Static Variable" };
thread_local Tracer t2 { "Thread-local Variable "};

int main() {
  const auto t2_ptr = &t2;
  std::cout << "A\n";
  Tracer t3{ "Automatic Variable" };
  std::cout << "B\n";
  const auto* t4 = new Tracer { "Dynamic Variable" };
  std::cout << "C\n";
  // delete t4; // Invokes ~Tracer on `t4`
}
