// prefix + suffix pass, T: O(n), S: O(1)

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<int> out(n);

        out[0] = 1;
        for (int i = 1; i < n; i++) {
            out[i] = out[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            out[i] *= right;
            right *= nums[i];
        }
        return out;
    }
};


// single right accum: elimintes sep suffix arr, save O(n) space
// out[0] = 1 and right = 1: init elem for mul
// mul over div: break on 0's, 20-40 cycle for div vs ~3 for mul
