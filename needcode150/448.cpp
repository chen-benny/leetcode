// hash-set, T: O(n), S: O(n)

#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::unordered_set<int> seen(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());

        std::vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (!seen.contains(i)) { res.push_back(i); }
        }
        return res;
    }
};

// flag-boolean array, values in [1, n], T: O(n), S: O(n) stack-allocated

#include <vector>
#include <cstring>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        constexpr int MAX_N = 100001;
        bool seen[MAX_N];
        std::memset(seen, 0, sizeof(seen));

        for (int x : nums) { seen[x] = true; }

        int n = static_cast<int>(nums.size());
        std::vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) { res.push_back(i); }
        }
        return res;
    }
};

// index-marking, negate nums[|x|-1] as visited flag, T: O(n), S: O(1)

#include <vector>
#include <cstdlib>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        for (int x : nums) {
            int idx = std::abs(x) - 1;
            if (nums[idx] > 0) { nums[idx] = -nums[idx]; }
        }

        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) { res.push_back(i + 1); }
        }
        return res;
    }
};

// cycle-sort, indices where nums[i] != i + 1 after sort are missing, T: O(n), S: O(1)

#include <vector>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int i = 0;
        while (i < n) {
            int correct = nums[i] - 1;
            if (nums[i] != nums[correct]) {
                std::swap(nums[i], nums[correct]);
            } else {
                ++i;
            }
        }

        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) { res.push_back(i + 1); }
        }
        return res;
    }
};

/*
   - index-marking vs cycle-sort
   ? dupcalite & missing values simultaneously
   ? combing duplicate & missing values in one pass
*/
