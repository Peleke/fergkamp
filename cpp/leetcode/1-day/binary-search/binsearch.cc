#include <iostream>
#include <vector>

auto binsearch(const std::vector<int>& nums, int target) -> int {
  // compute lo, hi; default initialize mid
  auto lo{ 0 };
  auto hi { int(nums.size() - 1) };
  int mid{};

  // search until lo pointer crosses hi
  while (lo <= hi) {
    // compute midpoint after updating lo and hi
    mid = lo + (hi - lo) / 2;
    // if search hit, return index
    if (nums[mid] == target) {
      return mid;
    // if miss and target > nums[mid], throw away low half
    } else if (nums[mid] < target) {
      lo = mid + 1;
    // if miss and target < nums[mid], throw away high half
    } else if (nums[mid] > target) {
      hi = mid - 1;
    }
  }
  // search missed and array exhausted -- return -1
  return -1;
}

auto main() -> int {
  std::vector<int> nums{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::cout << binsearch(nums, -10) << '\n';
  std::cout << binsearch(nums, 5) << '\n';
}