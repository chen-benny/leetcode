#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp2 = 0;
        int dp1 = 0;

        for (int val : nums) {
            int cur = max(dp2 + val, dp1);
            dp2 = dp1;
            dp1 = cur;
        }

        return dp1;
    }
};
