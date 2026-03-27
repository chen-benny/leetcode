// hash-set, T: O(n), S: O(n)

#include <vector>
#include <unordered_set>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        std::unordered_set<int> seen(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        for (int i = 1; i <= n + 1; i++) {
            if (!seen.contains(i)) { return i; }
        }
        return n + 1;
    }
};

// index-marking, values outside [1, n] are irrelevant, T: O(n), S: O(n)

#include <vector>
#include <cstdlib>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        for (int& x : nums) { // clamp out-of-range values to n + 1
            if (x <= 0 || x > n) { x = n + 1; }
        }
        
        for (int i = 0; i < n; i++) { // negate nums[|x| - 1] to mark seen
            int val = std::abs(nums[i]);
            if (val <= n) { nums[val - 1] = -std::abs(nums[val - 1]); }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) { return i + 1; }
        }
        return n + 1;
    }
};

// cycle-sort, first index where nums[i] != i + 1 is the answer, T: O(n), S: O(1)

#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int i = 0;

        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n) {
                int correct = nums[i] - 1; // need bound check first
                if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correct]) { std::swap(nums[i], nums[correct]); }
                else { ++i; }
            } else {
                ++i;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) { return i + 1; }
        } 
        return n + 1;
    }
};

/*
   - why clamp to n + 1 in index-marking
   - cycle-sort termination
   - index-marking vs cycle-sort
   ? why answers need to be in [1, n + 1]
   ? all values are negative
   ? without modifying the input
*/
