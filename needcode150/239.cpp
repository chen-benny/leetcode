// monotonic-deque, deque of indices in decreasing order of values, front holds max of cur win, T: O(n), S: O(k)

#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> dq; // indices, front = max of cur win
        std::vector<int> res;
        res.reserve(static_cast<int>(nums.size()) - k + 1);

        for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
            if (!dq.empty() && dq.front() < right - k + 1) { dq.pop_front(); }

            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }
            dq.push_back(right);

            if (right >= k - 1) { res.push_back(nums[dq.front()]); }
        }
        return res;
    }
};

/*
   - why store indices
   - deque overhead
   - amortized o(1) per elem
   ? k = 1
   ? equal elements
   ? extend to min sliding win
   ? real-world analogy
*/
