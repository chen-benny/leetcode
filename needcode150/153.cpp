// binary-search, T: O(log(n)), S: O(1)

#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int lo = 0;
        int hi = static_cast<int>(nums.size()) - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] > nums[hi]) { lo = mid + 1; } // min in right half
            else { hi = mid; } // min in left half or mid
        }
        return nums[lo];
    }
};

/*
   - nums[mid] > nums[hi] over nums[lo]
   - why lo < hi
   ? nums[mid] == nums[hi]
   ? without binary search
*/
