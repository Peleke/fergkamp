#include <cmath>
#include <iostream>
using namespace std;

double rbinary_search(double *array, size_t n_elements, double target, double lo, double hi) {
    /*
     * Perform a recursive binary search for `target` on `array`, which is assumed to be sorted.
     *
     * Complexity
     *   Time   O(lg n)
     *   Space  O(lg n) (w/o TCO)
     *
     * :param array: List of elements to search.
     * :type array: List[Any]
     *
     * :param target: Element to search for.
     * :type target: Any
     *
     * :return: Return the element matching `target` if the search succeeds, or `-1` otherwise.
     * :rtype: Union[Any, int]
    */
    int mid = std::round((lo + hi) / 2);
    if (n_elements >= 1) {
      // If pointers have crossed, search missed
      if (lo == hi) {
        return -1;
      } else if (array[mid] == target) {
        // If hit, return index at which `target` lives in `array`
        return mid;
      } else if (array[mid] < target) {
        // If missed and `target > array[mid]`, recurse with lo = mid + 1
        return rbinary_search(
          array, n_elements, target, mid + 1, hi
        );
      } else if (array[mid] > target) {
        // If missed and `target > array[mid]`, recurse with hi = mid - 1
        return rbinary_search(
          array, n_elements, target, lo, mid - 1
        );
      }
    }
    // Suppresses -Wreturn-type warning...?
    return -1;
}

int main() {
  // Brace-initialize array...
  double array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int length = sizeof(array) / sizeof(double);
  // Test...
  for (int i = -1; i < 12; i++) {
    double result = rbinary_search(array, length, i, 0, length - 1);
    if (result == -1) {
      // Should miss -1, 0, 11, 12
      std::cout << "SEARCH MISSED for " << i << "\n";
    } else {
      // Should hit 1-10 (cf. `array`)
      std::cout << "SEARCH HIT: " << result << "\n";
    }
  }
}