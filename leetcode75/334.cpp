#include <climits>

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int val1 = INT_MAX;
        int val2 = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] <= val1) {
                val1 = nums[i];
            } else if (nums[i] <= val2) {
                val2 = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};
