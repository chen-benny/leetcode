#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) { return {}; }
        vector<string> res;
        string curr;
        curr.reserve(digits.size());

        backtrack(digits, res, curr, 0);

        return res;
    }

private:
    static constexpr const char* mapping[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(const string& digits, vector<string>& res, string& curr, int idx) {
        if (idx == static_cast<int>(digits.size())) {
            res.push_back(curr);
            return;
        }

        for (const char* ch = mapping[digits[idx] - '0']; *ch; ch++) {
            curr.push_back(*ch);
            backtrack(digits, res, curr, idx + 1);
            curr.pop_back();
        }
    }
};

// follow-up: iter-bfs

#include <utility>

using std::swap;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) { return {}; }
        static constexpr const char* mapping[10] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> curr_lv = {""};
        vector<string> next_lv = {};

        for (char d : digits) {
            for (const string& prev : curr_lv) {
                for (const char* ch = mapping[d - '0']; *ch; ch++) {
                    next_lv.push_back(prev + *ch);
                }
            }

            swap(curr_lv, next_lv);
            next_lv.clear();
            next_lv.reserve(curr_lv.size() * 4);
        }

        return curr_lv;
    }
};
