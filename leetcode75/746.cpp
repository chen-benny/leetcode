#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = static_cast<int>(cost.size());
        int dp1 = 0;
        int dp2 = 0;

        for (int i = 2; i <= n; i++) {
            int cur = min(dp2 + cost[i - 2],
                          dp1 + cost[i - 1]);
            dp2 = dp1;
            dp1 = cur;
        }

        return dp1;
    }
};
