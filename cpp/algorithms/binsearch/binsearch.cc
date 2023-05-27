#include <cmath>
#include <iostream>
using namespace std;

double binary_search(double *array, size_t n_elements, double target) {
    /*
     * Perform binary search for `target` on `array`, which is assumed to be sorted.
     *
     * Complexity
     *   Time   O(lg n)
     *   Space  O(1)
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
    // Initialize `lo` (lower bond), `hi` (upper bound), and `mid` (index to test against `target`)
    double lo = 0;
    double hi = n_elements;
    int mid = std::round((lo + hi) / 2);

    // Test `array[mid]` until lower bound passes upper bound (i.e., until all viable regions have been checked)
    while (lo < hi) {
      // Return `mid` if `target` is in array
      if (array[mid] == target) {
        return mid;
      // If `target > array[mid]`, throw out left half of array
      } else if (array[mid] < target) {
        // Set lower bound to one greater than current midpoint -- required for termination (!)
        lo = mid + 1;
      // If `target < array[mid]`, throw out right half of array
      } else if (array[mid] > target) {
        // Set upper bound to one less than current midpoint -- required for termination (!)
        hi = mid - 1;
      }
      // Reset `mid` 
      mid = std::round((lo + hi) / 2);
    }
    return -1;
}

int main() {
  // Brace-initialize array...
  double array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  // Test...
  for (int i = -1; i < 12; i++) {
    double result = binary_search(array, sizeof(array) / sizeof(double), i);
    if (result == -1) {
      // Should miss -1, 0, 11, 12
      cout << "SEARCH MISSED for " << i << "\n";
    } else {
      // Should hit 1-10 (cf. `array`)
      cout << "SEARCH HIT: " << result << "\n";
    }
  }
}