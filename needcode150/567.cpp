// sliding-window + flat-array, T: O(n + m), S: O(1) stack-allocated

#include <string>
#include <cstring>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size()) { return false; }
        
        constexpr int ALPHA_SIZE = 26;
        constexpr char BASE_CHAR = 'a';

        int freq[ALPHA_SIZE];
        std::memset(freq, 0, sizeof(freq));

        for (char c : s1) { ++freq[c - BASE_CHAR]; }

        int need = static_cast<int>(s1.size());
        int win_size = static_cast<int>(s1.size());
        int have = 0;
        int left = 0;
        

        for (int right = 0; right < static_cast<int>(s2.size()); ++right) {
            int rc = s2[right] - BASE_CHAR;
            if (freq[rc] > 0) { ++have; }
            --freq[rc];

            if (right - left + 1 > win_size) {
                int lc = s2[left++] - BASE_CHAR;
                ++freq[lc];
                if (freq[lc] > 0) { --have; }
            }

            if (have == need) { return true; }
        }
        return false;
    }
};

/*
   - early exit
   - cache behavior
   ? s1 has all identical chars
   ? early exit if a char of s2 never appear in s1
*/
