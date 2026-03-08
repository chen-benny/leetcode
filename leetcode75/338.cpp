#include <vector>

using std::vector;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0); 
        for (int i = 0; i <= n; i++) {
            res[i] = count_one(i);
        }
        return res;
    }

private:
    int count_one(int x) {
        int cnt = 0;
        while (x != 0) {
            x &= x - 1; // x - 1 flips the lowest 1 bit and all bits below it; x & (x-1) zeros out only this 1 bit
            ++cnt;
        }
        return cnt;
    }
};



// follow-up: dp-1d

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i & (i-1)] + 1; // i & (i-1) removes the lowest bit
        }
        return dp;
    }
};

// follow-up: dp-1d, right shift
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1); // stripe lowest bit + lowest bit
        }
        return dp;
    }
};

