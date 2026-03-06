class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) { return 0; }
        if (n <= 2) { return 1; }

        int dp3 = 0;
        int dp2 = 1;
        int dp1 = 1;
        for (int i = 3; i <= n; i++) {
            int next = dp3 + dp2 + dp1;
            dp3 = dp2;
            dp2 = dp1;
            dp1 = next;
        }

        return dp1;
    }
};
