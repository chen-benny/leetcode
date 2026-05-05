// binary-search, T: O(log(n)), S: O(1)

#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int lo = 0;
        int hi = static_cast<int>(nums.size()) - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1]) { lo = mid + 1; }
            else { hi = mid; }
        }
        return lo;
    }
};

// binary-search on unsorted array:
//   nums[-1] = nums[n] = -inf; all elements distinct
//   nums[mid] < nums[mid + 1] guarantees a peak exists to the right
// lo < hi termination: hi = mid include mid as the peak
