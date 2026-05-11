// backtracking, T: O(4^n/n^1/2) Catalan number, S: O(n) recursion depth

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> out;
        std::string curr;
        curr.reserve(2 * n);
        backtrack(out, curr, 0, 0, n);
        return out;
    }

private:
    void backtrack(std::vector<std::string>& out, std::string& curr,
                   int open, int close, int n) {
        if (static_cast<int>(curr.size()) == 2 * n) {
            out.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            backtrack(out, curr, open + 1, close, n);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            backtrack(out, curr, open, close + 1, n);
            curr.pop_back();
        }
    }
};

// two branches not inside loop: minimal branching, compiler could inline both
// close < open not close < n: ensure parenthesis always pair
