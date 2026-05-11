// backtracking, T: O(kC(n,k)), S: O(k) recursion depth

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> out;
        std::vector<int> curr;
        curr.reserve(k);
        backtrack(n, k, 1, curr, out);
        return out;
    }

private:
    void backtrack(int n, int k, int start,
                   std::vector<int>& curr,
                   std::vector<std::vector<int>>& out) {
        if (static_cast<int>(curr.size()) == k) {
            out.push_back(curr);
            return;
        }

        int need = k - static_cast<int>(curr.size());
        for (int i = start; i <= n - need + 1; ++i) {
            curr.push_back(i);
            backtrack(n, k, i + 1, curr, out);
            curr.pop_back();
        }
    }
};

// pruning i< = n-need+1: need = k-curr.size(), n-i+1 >= need ~ [i, n] has at least need
// i+1 not i: no reuse of elem
// n-need+1 not n-need: inclusive upper bound
