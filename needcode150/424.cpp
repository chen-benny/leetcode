// sliding-window + flat-array, valid win when (win_size) - (max freq char cnt) <= k, T: O(n), S: O(1) stack-allocated

#include <string>
#include <cstring>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        constexpr int ALPHA_SIZE = 26;
        constexpr char BASE_CHAR = 'A';

        int freq[ALPHA_SIZE];
        std::memset(freq, 0, sizeof(freq));

        int left = 0;
        int maxFreq = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            int rc = s[right] - BASE_CHAR;
            ++freq[rc];
            maxFreq = std::max(maxFreq, freq[rc]);

            while ((right - left + 1) - maxFreq > k) {
                --freq[s[left] - BASE_CHAR];
                ++left;
            }

            best = std::max(best, right - left + 1);
        }
        return best;
    }
};

/*
   - maxFreq neve decreases
   - why O(n) over O(n*26)
   - cache behavior
   ? while for thrinking over if
   ? k >= n
*/
