// hash-map one pass, T: O(n), S: O(n)

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        std::unordered_map<int, int> seen; // val: idx of nums[]
        seen.reserve(n);
        seen.max_load_factor(0.25f);

        for (int i = 0; i < n; ++i) {
            int comp = target - nums[i];
            auto it = seen.find(comp);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

// flat-array, [-1e4, 1e4] T: O(n), S: O(1) stack-allocated 

#include <vector>
#include <cstring> // std::memset

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        constexpr int MIN_VAL = -10000;
        constexpr int MAX_VAL = 10000;
        constexpr int OFFSET = -MIN_VAL;
        constexpr int RANGE = MAX_VAL - MIN_VAL + 1;

        int table[RANGE];
        std::memset(table, -1, sizeof(table));

        for (int i = 0; i < n; ++i) {
            int comp = target - nums[i];
            if (comp >= MIN_VAL && comp <= MAX_VAL && table[comp + OFFSET] != -1) {
                return {table[comp + OFFSET], i};
            }
            table[nums[i] + OFFSET] = i;
        }
        return {};
    }
};

// table[RANGE]: ~20001 * 4 bytes ~= 80000 bytes ~= 80KB (L1/L2 cache)
// memset with -1: -1 in 2's complement is 0xFF
// absl::flat_hash_map: unbounded range open-addressed flat layout
//   - 2-4 faster than std::unordered_map for interger keys
//   - no pointer chasing, keys and values stored inline
// [1e-9, 1e9] requires 4GB stack memory
