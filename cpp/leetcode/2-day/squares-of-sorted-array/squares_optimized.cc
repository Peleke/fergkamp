#include <iostream>
#include <vector>

/*
 * This solution to the sorted squares problem eliminates most of the incidental complexity of the previous one, giz.:
 * - The solution generalizes to all cases -- no ad-hoc checks required
 * - Boundary search is eliminated, reducing constant terms
 * 
 * Time Complexity remains O(n), with reduced constant factors due to omission of the linear/binary search.
 * Space Complexity remains O(n), due to the allocation of a secondary vector with size identical to the input.
 */

void showVector(const std::vector<int> vec) {
  for (auto val : vec) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
}

auto abs(const int x) -> int {
  if (x < 0) {
    return -x;
  }
  return x;
}

auto square(const int x) -> int {
  return x * x;
}

auto sortedSquares(const std::vector<int>& nums) -> std::vector<int> {
  // initialize a new vector with exact size to avoid underlying resize
  std::vector<int> output;
  output.reserve(nums.size());
  // init front, back, and insertion pointers...
  unsigned int lo = 0;
  unsigned int hi = int(nums.size()) - 1;
  unsigned int insert_position = int(nums.size() - 1);
  // until pointers cross...
  while (lo <= hi) {
    // ...insert the number producing the larger square and insert, starting at the back
    if (abs(nums[lo]) > abs(nums[hi])) {
      output[insert_position] = square(nums[lo]);
      lo += 1;
    } else {
      output[insert_position] = square(nums[hi]);
      hi -= 1;
    }
    insert_position -= 1;
  }
  return output;
}

auto main() -> int {
  std::vector<int> nums{ -3, -1, 0, 1, 2, 3, 4, 5 };
  showVector(sortedSquares(nums));
}