// greedy + monotonic-stack, T: O(n), S: O(1) - at most 26 chars on stack

#include <string>
#include <cstring>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        constexpr int ALPHA_SIZE = 26;
        constexpr char BASE_CHAR = 'a';

        int lastIdx[ALPHA_SIZE]; // last occuro idx of each char
        bool inStack[ALPHA_SIZE]; // is char already in result
        std::memset(lastIdx, 0, sizeof(lastIdx));
        std::memset(inStack, 0, sizeof(inStack));

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            lastIdx[s[i] - BASE_CHAR] = i;
        }
        std::stack<char> stk;

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            int c = s[i] - BASE_CHAR;
            if (inStack[c]) { continue; }

            while (!stk.empty() && s[i] < stk.top() && lastIdx[stk.top() - BASE_CHAR] > i) {
                inStack[stk.top() - BASE_CHAR] = false;
                stk.pop();
            }

            stk.push(s[i]);
            inStack[c] = true;
        }

        std::string res;
        res.resize(stk.size());
        for (int i = static_cast<int>(stk.size()) - 1; i >= 0; --i) {
             res[i] = stk.top();
             stk.pop();
        }
        return res;
    }
};

/*
   - lastIdx[c] > i
   - inStack for O(1) dup check
   - stack -> string re-construction
   ? greedy
   ? invariant of stack at any point
*/
