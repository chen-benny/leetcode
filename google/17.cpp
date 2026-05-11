// backtracking, T: O(n4^n), S: O(n) recursion path

#include <vector>
#include <string>

class Solution {
private:
    static constexpr const char* MAP[] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void backtrack(const std::string& digits, int idx,
                   std::string& curr, std::vector<std::string>& res) {
        if (idx == static_cast<int>(digits.size())) {
            res.push_back(curr);
            return;
        }

        for (const char* c = MAP[digits[idx] - '0']; *c; ++c) {
            curr.push_back(*c);
            backtrack(digits, idx + 1, curr, res);
            curr.pop_back();
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) { return {}; }
        std::vector<std::string> res;
        std::string curr;
        curr.reserve(digits.size());
        backtrack(digits, 0, curr, res);
        return res;
    }
};

// static constexpr const char* MAP[]: compile-time string table
// for (const char* c = MAP[...]; *c; ++c): null-terminated scan
// cache MAP is read-only literals, curr modified in-place, no allocation
