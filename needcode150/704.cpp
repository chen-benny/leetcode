// binary-search, T: O(log(n)), S: O(1)

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int lo = 0;
        int hi = static_cast<int>(nums.size()) - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) { return mid; }
            else if (nums[mid] < target) { lo = mid + 1; }
            else { hi = mid - 1; }
        }
        return -1;
    }
};

/*
   - cache behavior
   - branch prediction
   ? linear scan wins
   ? lo <= hi termination
*/
