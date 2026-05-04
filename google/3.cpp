// sliding-window + char-index array, T: O(n), S: O(1) stack-allocated

#include <string>
#include <cstring> // std::memset
#include <algorithm> // std::max

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = static_cast<int>(s.size());
        constexpr int ALPHA_SIZE = 128;
        constexpr int NOT_SEEN = -1;

        int last[ALPHA_SIZE]; // last[i] := last index of char c at i
        std::memset(last, NOT_SEEN, sizeof(last));

        int left = 0, best = 0;
        for (int right = 0; right < n; ++right) {
            int c = static_cast<unsigned char>(s[right]);
            if (last[c] >= left) { left = last[c] + 1; }
            last[c] = right;
            best = std::max(best, right - left + 1);
        }
        return best;
    }
};

// last[128]: 128 * 4bytes = 512 bytes, fits entire in L1
// direct jump left = last[c] + 1
// memset with -1
// static_cast<unsigned char>: cast zero-extends to [0, 127] in case signed char within [0, 255]
// unicode: hash-map to contain 1M+ code points
