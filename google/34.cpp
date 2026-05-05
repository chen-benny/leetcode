// two binary-searches, T: O(log(n)), S: O(1)

#include <vector>
#include <algorithm> // std::lower_bound, std::upper_bound

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto first = std::lower_bound(nums.begin(), nums.end(), target);
        if (first == nums.end() || *first != target) { return {-1, -1}; }

        auto last = std::upper_bound(first, nums.end(), target); // starting from first
        return {static_cast<int>(first - nums.begin()),
                static_cast<int>(last - nums.begin()) - 1};
    }
};

// first search warms the cache lines for the second
// lower_bound vs upper_bound: [first, last) of target
//   lower_bound: first element >= target
//   upper_bound: first element > target

// self-impl version

#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int first = lower_bound(nums, 0, n, target);
        if (first == n || nums[first] != target) { return {-1, -1}; }
        int last = upper_bound(nums, first, n, target);
        return {first, last - 1};
    }

private:
    // Returns index of first element >= target
    int lower_bound(std::vector<int>& nums, int lo, int hi, int target) {
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) { lo = mid + 1; }
            else { hi = mid; }
        }
        return lo;
    }

    // Return index of first element > target
    int upper_bound(std::vector<int>& nums, int lo, int hi, int target) {
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target) { lo = mid + 1; }
            else { hi = mid; }
        }
        return lo;
    }
};
