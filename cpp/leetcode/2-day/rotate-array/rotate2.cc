#include <algorithm>
#include <iostream>
#include <vector>

auto showVector(const std::vector<int> vec) -> void {
  for (auto val : vec) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
}

auto swapPosition(std::vector<int>& nums, int left, int right) -> std::vector<int> {
  int temp = nums[left];
  nums[left] = nums[right];
  nums[right] = temp;

  return nums;
}

auto reverseRange(std::vector<int>& nums, int lo, int hi) -> std::vector<int> {
  while (lo < hi) {
    swapPosition(nums, lo, hi);
    lo += 1;
    hi -= 1;
  }
  return nums;
}

auto rotateArray(std::vector<int>& nums, int k) -> std::vector<int> {
  // "wrap" in case k > nums.size()
  k = k % nums.size();
  if (nums.size() == 0 || k == 0) {
    return nums;
  } else {
    // reverse whole list...
    nums = reverseRange(nums, 0, nums.size() - 1);
    // restore order up to `k`
    nums = reverseRange(nums, 0, k-1);
    // restore order after `k`
    return reverseRange(nums, k, nums.size() - 1);
  }
}

auto main() -> int {
  std::vector<int> nums{1, 2, 3, 4, 5};
  showVector(rotateArray(nums, nums.size()));
}