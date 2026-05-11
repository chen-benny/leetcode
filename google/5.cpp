// expand from center, T: O(n2), S: O(1)

#include <string>
#include <algorithm> // std::max

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = static_cast<int>(s.size());
        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; ++i) {
            // odd len
            int lo = i;
            int hi = i;
            while (lo > 0 && hi < n-1 && s[lo-1] == s[hi+1]) {
                --lo;
                ++hi;
            }
            if (hi - lo + 1 > maxLen) {
                maxLen = hi - lo + 1;
                start = lo;
            }

            // even len
            if (i + 1 < n && s[i] == s[i+1]) {
                lo = i;
                hi = i + 1;
                while (lo > 0 && hi < n-1 && s[lo-1] == s[hi+1]) {
                    --lo;
                    ++hi;
                }
                if (hi - lo + 1 > maxLen) {
                    maxLen = hi - lo + 1;
                    start = lo;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

// Manacher's Algorithm, T: O(n), S: O(n)

// Manacher's key insight: prev computed palindromes provide lower bound for new ones
