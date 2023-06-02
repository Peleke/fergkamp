#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdexcept>
using namespace std;

struct SimpleString {
  SimpleString(size_t max_size) : max_size{ max_size }, length{} {
    if (max_size == 0) {
      throw std::runtime_error{ "Max size must be at least 1." };
    }
    buffer = new char[max_size];
    buffer[0] = 0;
  }
  SimpleString(const SimpleString& other)
    : max_size { other.max_size },
    buffer { new char[other.max_size] },
    length { other.length } {
    std::strncpy(buffer, other.buffer, max_size);
  }
  SimpleString& operator=(const SimpleString& other) {
    if (this == &other) return this;
    const auto new_buffer = new char[other.max_size];
    delete[] buffer;
    buffer = new_buffer;
    length = other.length;
    max_size = other.max_size;
    std::strncpy(buffer, other.buffer, max_size);
    return *this;
  })
  ~SimpleString() {
    delete[] buffer;
  }
  void print(const char* tag) const {
    printf("%s: %s", tag, buffer);
  }
  bool append_line(const char* x) {
    const auto x_len = strlen(x);
    if (x_len + length + 2 > max_size) {
      return false;
    }
    std::strncpy(buffer + length, x, max_size - length);
    length += x_len;
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }
private:
  size_t max_size;
  char* buffer;
  size_t length;
};

struct SimpleStringOwner {
  SimpleStringOwner(const char* x) : string { 10 } {
    if (!string.append_line(x)) {
      throw std::runtime_error{ "Not enough memory for x!\n" };
    }
    std::cout << "Constructed\n";
  }
  ~SimpleStringOwner() {
    std::cout << "About to destroy...\n";
  }
private:
  SimpleString string;
};

int main() {
  SimpleString string{ 115 };
  string.append_line("Starbuck, whaddya hear?");
  string.append_line("Nothing but the rain.");
  string.print("A");
  string.append_line("Grab your gun and bring the cat in.");
  string.append_line("Aye-aye, sir, coming home.");
  string.print("B");
  if (!string.append_line("Galactica!")) {
    printf("String was not big enough to append another message.\n");
  }

  SimpleStringOwner x { "x" };
  std::cout << "x is alive\n";
  // Testing Copy Constructor
  SimpleString b = SimpleString{ b };
  b.print("NEW");

  printf("A: %x\n", &string);
  printf("B: %x\n", &b);
}