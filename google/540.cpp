// binary-search, T: O(log(n)), S: O(1)

#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int lo = 0;
        int hi = static_cast<int>(nums.size()) - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid % 2 == 1) { --mid; } // ensure mid is even

            if (nums[mid] == nums[mid + 1]) { lo = mid + 2; }
            else { hi = mid; }
        }
        return nums[lo];
    }
};

// parity invariant: pair has nums[even] == nums[even + 1]; after single element has nums[odd] == nums[odd + 1]
// lo = mid + 2: only skip intact pair of [mid, mid + 1]
// hi = mid: mid itself may still be the single element
// XOR not qualify: still O(n), correct for unsorted arrays
// one element case: lo == hi
