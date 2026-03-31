// sliding-window + hash-set, expand right, shrink left when dup found, T: O(n), S: O(min(n, m)), m = alphabet size

#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> seen;
        seen.reserve(128);
        seen.max_load_factor(0.25f);
        int left = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            while (seen.count(s[right])) { seen.erase(s[left++]); }
            seen.insert(s[right]);
            best = std::max(best, right - left + 1);
        }
        return best;
    }
};

// sliding-window + last-seen-index + flat-array
// store last seen idx per char, jump left directly, no inner loop, T: O(n), S: O(1)

#include <string>
#include <cstring>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        constexpr int ALPHA_SIZE = 128;
        constexpr int NOT_SEEN = -1;

        int last[ALPHA_SIZE];
        std::memset(last, NOT_SEEN, sizeof(last));

        int left = 0;
        int best = 0;
        for (int right = 0; right <static_cast<int>(s.size()); ++right) {
            int ch = static_cast<unsigned char>(s[right]);
            if (last[ch] >= left) { left = last[ch] + 1; }
            last[ch] = right;
            best = std::max(best, right - left + 1);
        }
        return best;
    }
};

/*
   - why last[ch] > left instead of last[ch] != -1
   - memset with NOT_SEEN
   - cache behavior
   ? input contains unicode
   ? why jump left directly over shrinking one step
*/
