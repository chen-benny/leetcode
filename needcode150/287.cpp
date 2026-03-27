// hash-set, T: O(n), S: O(n)

#include <vector>
#include <unordered_set>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size());
        seen.max_load_factor(0.25f);

        for (int x : nums) {
            if (!seen.insert(x).second) { return x; }
        }
        return -1;
    }
};

// binary-search on value range, count (elem <= mid) > mid, dup in [1, mid], T: O(nlogn), S: O(1)

#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int lo = 1;
        int hi = static_cast<int>(nums.size()) - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0;
            for (int x : nums) {
                if (x <= mid) { ++count; }
            }
            if (count > mid) { hi = mid; }
            else { lo = mid + 1; }
        }
        return lo;
    }
};

// bit-manipulation, excess bits belong to dup, T: O(nlogn), S: O(1)

#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size()) - 1;
        int dup = 0;
        constexpr int BITS = 32;

        for (int bit = 0; bit < BITS; bit++) {
            int mask = 1 << bit;
            int expect = 0; // count of nums in [1,n] with this bit set
            int actual = 0; // count in nums

            for (int i = 1; i <= n; i++) {
                if (i & mask) { ++expect; }
            }
            for (int x : nums) {
                if (x & mask) { ++actual; }
            }

            if (actual > expect) { dup |= mask; }
        }
        return dup;
    }
};

// Floyd's Cycle Detection, treat array as linked-list: node i points to nums[i]
// dup values means two nodes point to the same next: forming a cycle, T: O(n), S: O(1)

#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        // find intersection inside cycle
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // find cycle entry - the dup val
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/*
   - why Floyd's over index-marking
   - Floyd's phase 2 correctness
   - binary-search on value range
   - bit-manipulation handles multiple duplicate
   ? why the array forming a linked list with a cycle
   ? can Floyd's detect with multiple dup vals
   ? binary-search counts elems <= mid
*/
