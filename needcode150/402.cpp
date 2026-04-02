// greedy + monotonic-stack, T: O(n), S: O(n)

#include <string>
#include <algorithm>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::string stk;
        stk.reserve(num.size());

        for (char c : num) {
            while (k > 0 && !stk.empty() && c < stk.back()) {
                stk.pop_back();
                --k;
            }
            stk.push_back(c);
        }

        while (k-- > 0) { stk.pop_back(); } // remove from end if k still > 0

        int start = 0;
        while (start < static_cast<int>(stk.size()) - 1 && stk[start] == '0') { // strip leading zeros
            ++start;
        }

        return stk.empty() ? "0" : stk.substr(start);
    }
};

/*
   - std::string as stack
   - remove from end when k > 0 after loop
   - leading zero stripping
   - empty test
   ? greedy
   ? k >= n
*/
