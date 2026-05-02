// char-index array, T: O(n), S: O(1) stack-allocated

#include <string>
#include <cstring> // std::memset

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) { return false; }

        constexpr int ALPHA_SIZE = 26;
        constexpr int BASE = 'a';

        int freq[ALPHA_SIZE];
        std::memset(freq, 0, sizeof(freq));

        for (char c : s) { freq[c - BASE]++; }
        for (char c : t) {
            if (--freq[c - BASE] < 0) { return false; }
        }
        return true;
    }
};

// freq[26]: 26 * 4bytes = 104 bytes, fits in two cache lines in L1
// early exist on decrement over one-pass version
// memset with 0
// unicode extension: std::unordered_map<char32_t, int>
