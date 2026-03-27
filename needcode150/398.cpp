// hash-map, T: O(1) pick, T: O(n)

#include <vector>
#include <unordered_map>
#include <cstdlib>

class Solution {
    std::unordered_map<int, std::vector<int>> indices;

public:
    Solution(std::vector<int>& nums) {
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            indices[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto& v = indices[target];
        return v[std::rand() % v.size()];
    }
};

// reservoir sampling, T: O(n) per pick, S: O(1)

#include <vector>
#include <cstdlib>

class Solution {
    std::vector<int> nums;

public:
    Solution(std::vector<int>& nums) : nums(nums) {}

    int pick(int target) {
        int res = -1;
        int count = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] != target) { continue; }
            ++count;
            if (std::rand() % count == 0) { res = i; }
        }
        return res;
    }
};

/*
   - hash-map vs reservoir
   - memory layout of hash-map
   ? nums is a stream of unknown length
   ? pick is called with a value not in nums
   ? make pick(logn) with O(n) space
*/
