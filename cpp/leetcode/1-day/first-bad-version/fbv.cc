#include <cstdio>
#include <iostream>
using namespace std;

auto neighbors(int x, int y) -> bool {
  // Determine if the difference between `x` and `y` equals 1
  if (abs(x - y) == 1) {
    return true;
  }
  return false;
}

auto isBadVersion(int n) -> bool {
  // Mocking LeetCode's provided function
  return n >= 5 ? true : false;
}

auto firstBadVersion(int n) -> int {
  // initialize `earliest_bad` (upper bound), `earliest_good` (lower bound), and `mid`
  int earliest_bad{ n };
  int earliest_good{ 0 };
  int mid{};

  while (true) {
    // compute mid
    mid = earliest_good + (earliest_bad - earliest_good) / 2;
    // check if is bad version
    if (isBadVersion(mid)) {
      // if this version is bad, reset `earliest_bad`/tighten upper bound
      if (mid < earliest_bad) {
        earliest_bad = mid;
      }
    } else {
      // otherwise, reset `earliest_good`/tighten lower bound
      if (mid > earliest_good) {
        earliest_good = mid;
      }
    }
    // if `earliest_bad` immediately follows `earliest_good`, return
    if (neighbors(earliest_bad, earliest_good)) {
      return earliest_bad;
    }
  }
}

auto main() -> int {
  std::cout << firstBadVersion(10) << "\n";
}