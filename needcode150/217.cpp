// sort, T: O(nlogn), S: O(1)

#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i = 1; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] == nums[i-1]) { return true; }
        }
        return false;
    }
};

// hash-set, T: O(n), S: O(n)

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size());
        seen.max_load_factor(0.25f);
        for (int x : nums) {
            if (!seen.insert(x).second) { return true; }
        }
        return false;
    }
};

// insert().second: insert returns {iterator, bool}, insert saves by single hash compute over find + insert
// sort alter: seq access + cache-friendly, better for small n or mem-constrained env
// reserve + max_load_factor(0.25f): pre-allocate exact cap, reduce collision chains, no rehash
// cache: absl::flat_hash_set avoids ptr chasing over node-based unordered_set, flat array best if able, int arr[10^6] ~ 4MB fit in L3
// sort vs hash-set: sort for no heap allocation or data nearly sorted; hash-set for early exit and mem avail

