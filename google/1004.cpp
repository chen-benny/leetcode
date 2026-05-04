// sliding-window, T: O(n), S: O(1)

#include <vector>
#include <algorithm> // std::max

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        int left = 0;
        int zeros = 0;
        int max_len = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == 0) { ++zeros; }

            if (zeros > k) {
                if (nums[left] == 0) { --zeros; }
                ++left;
            }

            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};

// if shrinking
