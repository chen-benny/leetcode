// monotonic-stack, indices in increasing heights, T: O(n), S: O(n)

#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = static_cast<int>(heights.size());
        std::stack<int> stk; // indices of mono-incre heights
        int best = 0;

        for (int i = 0; i <= n; ++i) {
            int curH = (i == n) ? 0 : heights[i];
            while (!stk.empty() && curH < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                best = std::max(best, h * w);
            }
            stk.push(i);
        }
        return best;
    }
};

/*
   - sentinel i == 0 with height 0
   - width omputation: i - stk.top() - 1
   - monotonic increasing vs decreasing
   - flat-array
   ? increasing over decreasing
   ? divide and conquer
*/
