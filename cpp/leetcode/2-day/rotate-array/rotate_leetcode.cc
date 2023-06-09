#include <vector>
using namespace std;

/*
 * This is the naive, linear-space solution, which solves the problem in the obvious way:
 * - Allocate a vector to be populated w/ the rotated contents of `nums`
 * - Establish pointer at index `nums.size() - k`
 * - Insert elements from indices `nums.size() - k` through `nums.size() - 1` into front of new vec
 * - Insert elements from indices 0 to `nums.size() - k - 1`
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // return immediately in trivial case
        if (nums.size() == 0) {
            return;
        } else {
            // wrap, in case k > nums.size()...
            k = k % nums.size();
            // init return vector -- `reserve` only necessary at true scale, but included for discussion's sake
            std::vector<int> output;
            output.reserve(nums.size());
            // init `start_from`, which identifies the number that should now be at the beginning of the array
            unsigned int start_from = nums.size() - k;
            // prepend `output` with elements from `start_from` onwards...
            for (int i = start_from; i < nums.size(); i += 1) {
              output.emplace_back(nums[i]);
            }
            // ...and append remaining elements after rotated block
            for (int i = 0; i < start_from; i += 1) {
              output.emplace_back(nums[i]);
            }
            nums = std::move(output);
        }
    }
};