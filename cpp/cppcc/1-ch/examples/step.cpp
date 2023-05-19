/* This program demonstrate sthe following:
 * - Single-line comments
 * - Multi-line comments (i.e., this)
 * - Variable assignment and typing
 * - Function definition and invocation
 * - Conditionals via if/else if/else 
 * - `printf` and the `%d` format string
*/
#include <cstdio>

int step(int arg) {
  // Assign `result` to 0
  int result = 0;

  // Test if less or greater than 0
  if (arg < 0) {
    result = -1;
  } else if (arg > 0) {
    result = 1;
  }

  // Return result -- already correct if arg == 0
  return result;
}

int main() {
  // Invoke `step` on `-100`, i.e., negative number/case
  int input1 = -100;
  int result1 = step(input1);
  printf("First Result: %d\n", result1);

  // Invoke `step` on `0`, i.e., zero case
  int input2 = 0;
  int result2 = step(input2);
  printf("Second Result: %d\n", result2);

  // Invoke `step` on `1`, i.e., positive number/case
  int input3 = 1;
  int result3 = step(input3);
  printf("Third Result: %d\n", result3);
}
