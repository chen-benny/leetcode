// sliding-window + flat-array, T: O(n + m), S: O(1) stack-allocated

#include <string>
#include <cstring>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size() < t.size()) { return ""; }

        constexpr int ALPHA_SIZE = 128;
        int freq[ALPHA_SIZE];
        std::memset(freq, 0, sizeof(freq));

        for (char c : t) { freq[static_cast<unsigned char>(c)]++; }

        int need = static_cast<int>(t.size());
        int left = 0;
        int best_left = 0;
        int best_len = INT_MAX;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            int rc = static_cast<unsigned char>(s[right]);
            if (freq[rc] > 0) { --need; }
            --freq[rc];

            while (need == 0) {
                if (right - left + 1 < best_len) {
                    best_len = right - left + 1;
                    best_left = left;
                }
                int lc = static_cast<unsigned char>(s[left++]);
                freq[lc]++;
                if (freq[lc] > 0) { ++need; }
            }
        }
        return best_len == INT_MAX ? "" : s.substr(best_left, best_len);
    }
};

/*
   - why have, need and freq[]
   - while have == need
   - freq[lc] > 0 guard
   - cache behavior
   ? why track best_left
   ? dup chars in t
*/
