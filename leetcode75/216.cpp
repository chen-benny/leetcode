#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        cur.reserve(k);

        backtrack(res, cur, k, n, 1);

        return res;
    }

private:
    void backtrack(vector<vector<int>>& res, vector<int>& cur, int k, int remain, int start) {
        if (static_cast<int>(cur.size()) == k) {
            if (remain == 0) { res.push_back(cur); }
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > remain) { break; } // prune: smallest candidate exceeds target
            cur.push_back(i);
            backtrack(res, cur, k, remain - i, i + 1);
            cur.pop_back();
        }
    }
};
