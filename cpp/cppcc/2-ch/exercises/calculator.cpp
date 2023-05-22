#include <cstdio>

enum class Operation {
  Add,
  Subtract,
  Multiply,
  Divide
};

struct Calculator {
  Calculator(Operation operation) {
    operation = operation;
  }
  int calculate(int a, int b) {
    switch(operation) {
      case Operation::Add: {
        return a + b;
      }
      case Operation::Subtract: {
        return a - b;
      }
      case Operation::Multiply: {
        return a * b;
      }
      case Operation::Divide: {
        return a / b;
      }
      default: {
        return -1;
      }
    }
  }
private:
  Operation operation{};
};

int main() {
  Calculator calculator = Calculator { Operation::Add };

  int a{ 1 };
  int b{ 2 };
  int c = calculator.calculate(a, b);

  printf("%d + %d = %d\n", a, b, c);
}