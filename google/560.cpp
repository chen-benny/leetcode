// prefix-sum + hash-map, T: O(n), S: O(n)

#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        std::unordered_map<int, int> freq;
        freq.reserve(n);
        freq.max_load_factor(0.25f);
        freq[0] = 1; // empty prefix

        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
            auto it = freq.find(sum - k);
            if (it != freq.end()) { count += it->second; }
            freq[sum]++;
        }
        return count;
    }
};

// flat-array fails: prefix-sum ranges too much
// freq[0] = 1: empty prefix sentinel
// absl::flat_hash_map over std::unordered_map
// reserve + max_load_factor(0.25) minimize collision and rehash
// freq for multiple subarray with the same prefix sum
// no int overflow (int max 2e9), long long with larger contraints
