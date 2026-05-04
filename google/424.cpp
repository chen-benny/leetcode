// sliding-window + char-index array, T: O(n), S: O(1) stack-allocated

#include <string>
#include <cstring> // std::memset
#include <algorithm> // std::max

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        constexpr int ALPHA_SIZE = 26;
        constexpr int BASE = 'A';

        int freq[ALPHA_SIZE];
        std::memset(freq, 0, sizeof(freq));

        int left = 0;
        int max_freq = 0;
        int max_len = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            int rc = s[right] - BASE;
            ++freq[rc];
            max_freq = std::max(max_freq, freq[rc]);

            if ((right - left + 1) - max_freq > k) {
                int lc = s[left] - BASE;
                --freq[lc];
                ++left;
            }

            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};

// freq[26]: 104 bytes fit in two cache lines in L1
// max_freq always increase
// if shrinking
// win_size - max_freq == min replacement
