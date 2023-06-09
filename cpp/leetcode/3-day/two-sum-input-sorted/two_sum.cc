#include <iostream>
#include <vector>

void showVector(const std::vector<int> vec) {
  for (auto val : vec) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
}

int search(std::vector<int>& numbers, int target) {
    int lo = 0;
    int hi = numbers.size() - 1;

    while (lo <= hi) { 
        int mid = lo + (hi - lo) / 2;
        if (numbers[mid] == target) {
            return mid;
        } else if (numbers[mid] < target) {
            lo = mid + 1;
        } else if (numbers[mid] > target) {
            hi = mid - 1;
        }
    }
    return -1;
}

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    // iterate from start and fix `k`
    std::vector<int> ret{-1, -1};
    for (int i = 0; i < numbers.size(); ++i) {
        // binary search for target - k  
        int target_index = search(numbers, target-numbers[i]);
        if (target_index != -1 && target_index != i) {
            if (target_index > i) {
                ret = std::vector{i + 1, target_index + 1};
            } else {
                ret = std::vector{target_index + 1, i + 1};
            }
        }
    }
    return ret;
}

int main() {
  std::vector<int> numbers{2,3,4};
  showVector(twoSum(numbers, 6));
}