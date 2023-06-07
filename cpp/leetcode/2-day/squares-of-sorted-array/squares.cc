#include <iostream>
#include<vector>
using namespace std;

/*
 * This solution performs a search to identify the boundary between negative and positive numbers,
 * then walks pointers down the negative sub-array and up the positive sub-array, comparing the 
 * square (implicitly) of each value to determine which should be inserted into the output array next.
 * 
 * Time complexity is O(n). We perform an O(n) search for the boundary, and then an O(n) 
 * "split linear" scan along subarrays to compute the squares. One could theoretically use
 * binary search to reduce the constant term. This is omitted, however, as it's a naive
 * Optimization: There is a way to skip the boundary search entirely (see `squares_optimized.cc`.)
 * 
 * Also note that there are several ad-hoc checks for monotonic positivity, null length, etc.
 * These _can_ be eliminated, but again, these optimizations are omitted, because there is a
 * generally more efficient solution that avoids both these checks as well as the linear/binary boundary
 * search.
 * 
 * Space complexity is O(n), as we allocate a vector with size equal to the original to store the squares.
 */
auto findBoundaryLinear(const vector<int>& nums) -> int {
  // Perform O(n) search for first positive number in list
  for (int i = 0; i < nums.size(); i += 1) {
    if (nums[i] >= 0) {
      return i;
    }
  }
  return -1;
}

auto square(int n) -> int {
  return n * n;
}

auto squareReverse(const vector<int>& nums) -> vector<int> {
  std::vector<int> squaredReversed{};
  for (int i = nums.size() - 1; i >= 0; i -= 1) {
    squaredReversed.push_back(square(nums[i]));
  }
  return squaredReversed;
}

auto squareVector(const vector<int>& nums) -> vector<int> {
  std::vector<int> squared{};
  for (auto num : nums) {
    squared.emplace_back(square(num));
  }
  return squared;
}

auto interweave(const vector<int>& nums, int pospointer, int negpointer) -> vector<int> {
  std::vector<int> interwoven{};
  while (pospointer < nums.size() || negpointer >= 0) {
    if (negpointer < 0) {
      // exhaust pos
      interwoven.emplace_back(square(nums[pospointer]));
      pospointer += 1;
    } else if (pospointer == nums.size()) {
      // exhaust neg
      interwoven.emplace_back(square(nums[negpointer]));
      negpointer -= 1;
    } else {
      // emplace lesser square 
      if (-nums[negpointer] <= nums[pospointer]) {
        interwoven.emplace_back(square(nums[negpointer]));
        negpointer -= 1;
      } else {
        interwoven.emplace_back(square(nums[pospointer]));
        pospointer += 1;
      }
    }
  }
  return interwoven;
}

auto sortedSquares(const vector<int>& nums) -> vector<int> {
  if (nums[0] > 0) {
    return squareVector(nums);
  } else {
    auto pospointer = findBoundaryLinear(nums);
    if (pospointer == -1) {
      return squareReverse(nums);
    } else {
      return interweave(nums, pospointer, pospointer-1);
    }
  }
}

void show_vector(const std::vector<int> vec) {
  for (auto val : vec) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
}

auto main() -> int {
  std::vector<int> nums{ -10, -5, -1, 0, 1, 5, 10 };
  std::vector<int> result = sortedSquares(nums);
  show_vector(result);
}