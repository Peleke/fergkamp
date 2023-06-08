#include <vector>
using namespace std;

// TODO: In-place
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // return immediately in trivial case
        if (nums.size() == 0) {
            return;
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
            nums = std::move(output);
        }
    }
};