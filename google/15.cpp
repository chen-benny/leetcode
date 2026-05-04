// sort + two-pointers, T: O(n^2), S: O(1)

#include <vector>
#include <algorithm> // std::sort

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        std::vector<std::vector<int>> out;

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) { break; } // sorted: 1st val must be neg
            if (i > 0 && nums[i] == nums[i - 1]) { continue; }

            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    out.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) { ++left; }
                    while (left < right && nums[right] == nums[right - 1]) { --right; }
                    ++left; --right;
                } else if (sum < 0) { ++left; }
                else { --right; }
            }
        }
        return out;
    }
};

// duplicate skipping: nums[i] == nums[i - 1]; inner left/right;
// early exist nums[i] > 0 due to sum == 0
