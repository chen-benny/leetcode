// Boyer-Moore Voting, T: O(n), S: O(1)

#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int cand = nums[0];
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (count == 0) {
                cand = nums[i];
                count = 1;
            } else if (nums[i] == cand) {
                count++;
            } else {
                count--;
            }
        }
        return cand;
    }
};

// Boyer-Moore works: majority element appears > n/2 times
// count == 0 reset: prev elements cancelled each other, this cand is irrelevant
// no guaranteed: add verify pass
// bit solu: for each bit pos, count elems has that bit set till count > n/2, O(32n) time, O(1) space
