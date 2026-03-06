class Solution {
public:
    int numTilings(int n) {
        if (n <= 1) { return 1; }
<<<<<<< HEAD
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
=======

        constexpr int MOD = 1'000'000'007;
        long long f2 = 1, f1 = 1; // f[i] = ways to fill up to col i without protrusion
        long long p1 = 0; // p[i] = ways to fill up to col i with one cell protruding to i+1

        for (int i = 2; i <= n; i++) {
            long long fcur = (f1 + f2 + 2 * p1) % MOD; // one-vert + two-hori + 2 * tri (protrusion on either top or bot)
            long long pcur = (f2 + p1) % MOD; // one-tri (create protrusion) + one-hori (extend protrusion)
            f2 = f1;
            f1 = fcur;
            p1 = pcur;
        }

        return static_cast<int>(f1);
>>>>>>> b1c0614 (binary-search + backtracking + dp-1d)
    }
};
