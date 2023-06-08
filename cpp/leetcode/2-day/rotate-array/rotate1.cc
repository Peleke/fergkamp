#include <iostream>
#include <vector>

void showVector(const std::vector<int> vec) {
  for (auto val : vec) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
}

auto rotateArray(std::vector<int>& nums, int k) -> std::vector<int> {
  if (nums.size() == 0) {
    return nums;
  } else {
    // wrap if k > nums.size()...
    k = k % nums.size();
    // init return vector 
    std::vector<int> output{};
    output.reserve(nums.size());
    // init `start_from`, which identifies the number that should now be at the beginning of the array
    int start_from{ int(nums.size() - k)};

    for (int i = start_from; i < nums.size(); i += 1) {
      output.emplace_back(nums[i]);
    }
    for (int i = 0; i < start_from; i += 1) {
      output.emplace_back(nums[i]);
    }
    return output;
  }
}

auto main() -> int {
  std::vector<int> nums{ 1, 2, 3, 4, 5 };
  showVector(rotateArray(nums, 3));
}