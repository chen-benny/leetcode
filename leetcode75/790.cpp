class Solution {
public:
    int numTilings(int n) {
        if (n <= 1) { return 1; }
        if (n == 2) { return 2; }

        constexpr int MOD = 1'000'000'007;
        long long dp3 = 1, dp2 = 1, dp1 = 2;

        for (int i = 3; i <= n; i++) {
            long long cur = (2 * dp1 % MOD + dp3) % MOD;
            dp3 = dp2;
            dp2 = dp1;
            dp1 = cur;
        }

        return static_cast<int>(dp1);
    }
};
