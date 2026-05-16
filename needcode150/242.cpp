// flat-array, bounded range, T: O(n), S: O(1) stack-allocated

#include <string>
#include <cstring> // std::memset

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) { return false; }
        constexpr int R = 26;
        constexpr char BASE = 'a';
        int freq[R];
        std::memset(freq, 0, sizeof(freq));

        for (char c : s) { freq[c-BASE]++; }
        for (char c : t) {
            freq[c-BASE]--;
            if (freq[c-BASE] < 0) { return false; }
        }
        return true;
    }
};

// freq[26] is 104 bytes: fit in two cache lines, L1 resident, no hash-compute, no ptr chasing
// early exit in looping t
// memset with 0 for int[]: all 0 bits, no 2's complement subtlety, memset is by-byte, only -1 and 0 is safe
// Unicode input: switch to std::unordered_map<char32_t, int>, flat-array infeasible for 1M+ code points
