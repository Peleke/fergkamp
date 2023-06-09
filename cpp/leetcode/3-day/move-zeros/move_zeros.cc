#include <iostream>
#include <vector>

auto showVector(const std::vector<int> vec) -> void {
  for (auto val : vec) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
}

auto swapPosition(std::vector<int>& nums, int lo, int hi) -> void {
  int tmp = nums[lo];
  nums[lo] = nums[hi];
  nums[hi] = tmp;
}

auto moveZeroes(std::vector<int>& nums) -> void {
  // register point to which to move non-zero elements
  int insertion_point = 0;

  // swap zeros with non-zero elements and update `insertion_point` as we go
  for (int i = 0; i < nums.size(); i += 1) {
    if (nums[i] != 0) {
      swapPosition(nums, i, insertion_point);
      ++insertion_point;
    }
  }
}

auto main() -> int {
  std::vector<int> nums{0, 1, 0, 3, 12};
  moveZeroes(nums);
  showVector(nums);
}