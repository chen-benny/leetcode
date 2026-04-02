// monotonic-stack + hash-map. T: O(m + n), S: O(m)

#include <vector>
#include <unordered_map>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1,
                                        std::vector<int>& nums2) {
        std::unordered_map<int, int> nextGt;
        nextGt.reserve(nums2.size());
        nextGt.max_load_factor(0.25f);

        std::stack<int> stk; // mono-decre vals of nums2

        for (int x : nums2) {
            while (!stk.empty() && x > stk.top()) {
                nextGt[stk.top()] = x;
                stk.pop();
            }
            stk.push(x);
        }

        std::vector<int> res;
        res.reserve(nums1.size());
        for (int x : nums1) {
            auto it = nextGt.find(x);
            res.push_back(it == nextGt.end() ? -1 : it->second);
        }
        return res;
    }
};

/*
   - hash-map or flat-array
   - mono-decre stk
   - amortized O(1)
   ? process nums2 on stack
*/
