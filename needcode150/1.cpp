// hash-map, T: O(n), S: O(n)

#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen; // {val: idx}
        seen.reserve(nums.size());
        seen.max_load_factor(0.25f);

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int val = nums[i];
            int comp = target - val;
            auto it = seen.find(comp);
            if (it != seen.end()) { return {it->second, i}; }
            seen[val] = i;
        }
        return {};
    }
};

// flat-array, T: O(n), S: O(R), R = value range, stack-allocated

#include <vector>
#include <algorithm> // std::fill

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        constexpr int BASE = -10'000;
        constexpr int R = 20'001; // [-10000, 10000]
        int table[R];
        std::fill(table, table + R, -1); // type-safe alter of std::memset

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int val = nums[i];
            int comp = target - val;
            if (comp >= BASE && comp < BASE + R && table[comp-BASE] != -1) {
                return {table[comp-BASE], i};
            }
            table[val-BASE] = i;
        }
        return {};
    }
};
