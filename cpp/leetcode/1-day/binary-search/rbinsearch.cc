#include <iostream>
#include <vector>

/*
 * This solution uses a recursive lambda to sweeten the recursive calls.
 * It looks a bit complicated, but produces fairly optimal assembly:
 * - Normal Recursion: https://godbolt.org/z/3E5anW
 * - Recursive Lambda: https://godbolt.org/z/fG3TdW 
 * Credit to: https://artificial-mind.net/blog/2020/09/12/recursive-lambdas
*/ 

auto rbinsearch(std::vector<int>& nums, int target) -> int {
  // capture `nums`, target` to simplify recursive args
  auto __rbinsearch = [nums, target](int lo, int hi, auto&& __rbinsearch) -> int {
      // compute `mid`
      auto mid{ lo + (hi - lo) / 2};
      if (lo >= hi) {
        // if pointers cross, search missed
        return -1;
      } else if (nums[mid] == target) {
        // if target found, return `mid`
        return mid;
      } else if (nums[mid] < target) {
        // if nums[mid] < target, throw away left/lower half
        return __rbinsearch(mid + 1, hi, __rbinsearch);
      } else if (nums[mid] > target) {
        // if nums[mid] > target, throw away right/upper half
        return __rbinsearch(lo, mid - 1, __rbinsearch);
      }
      // WARNING: lack of "default" return path evokes warning
    };
  // invoke lambda
  return __rbinsearch(0, nums.size() - 1, __rbinsearch);
}

auto main() -> int {
  std::vector<int> nums{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::cout << rbinsearch(nums, -10) << '\n';
  std::cout << rbinsearch(nums, 5) << '\n';
}