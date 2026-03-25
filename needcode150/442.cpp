// hash-set, T: O(n), S: O(n)

#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size());
        seen.max_load_factor(0.25f);

        std::vector<int> res;
        for (int x : nums) {
            if (!seen.insert(x).second) { res.push_back(x); }
        }
        return res;
    }
};

// flat-boolean-array, bounded range, T: O(n), S: O(n) stack-allocated

#include <vector>
#include <cstring>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        constexpr int MAX_N = 100001;
        bool seen[MAX_N];
        std::memset(seen, 0, sizeof(seen));

        std::vector<int> res;
        for (int x : nums) {
            if (seen[x]) {
                res.push_back(x);
            } else {
                seen[x] = true;
            }
        }
        return res;
    }
};

// index-marking, values in [1, n] map to indices [0, n-1], negate nums[|x|-1] as visited flag, T: O(n), S: O(1)

#include <vector>
#include <cstdlib>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> res;
        for (int x : nums) {
            int idx = std::abs(x) - 1;
            if (nums[idx] < 0){
                res.push_back(std::abs(x));
            } else {
                nums[idx] = -nums[idx];
            }
        }
        return res;
    }
};

// cycle-sort, nums[i] = i + 1, after sorting indices nums[i] != i + 1 hold duplicates, T: O(n), S: O(1)

#include <vector>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int i = 0;

        while (i < n) {
            int correct = nums[i] - 1;
            if (nums[i] != nums[correct]) {
                std::swap(nums[i], nums[correct]);
            } else {
                i++;
            }
        }

        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) { res.push_back(nums[i]); }
        }
        return res;
    }
};

/*
   - cache behavior
   - index-marking over cycle-sort
   - sign-bit as flag
   ? restore the array after index marking
   ? why cycle-sort terminates
   ? index marking on finding disappeared numbers
*/
