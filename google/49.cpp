// char-index array, T: O(nk), S: O(nk)

#include <vector>
#include <string>
#include <unordered_map>
#include <cstring> // std::memset

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
        constexpr int R = 26; // english chars
        constexpr char BASE = 'a';

        std::unordered_map<std::string, std::vector<std::string>> groups; // key -> [str,]
        groups.reserve(strs.size());
        groups.max_load_factor(0.25f);

        int freq[R];

        for (auto& s : strs) {
            std::memset(freq, 0, sizeof(freq));
            for (char c : s) { freq[c-BASE]++; }
            
            std::string key(R, '\0');
            for (int i = 0; i < R; ++i) { key[i] = static_cast<char>(freq[i]); }
            groups[key].push_back(s);
        }

        std::vector<std::vector<std::string>> out;
        out.reserve(groups.size());
        for (auto& [k, v] : groups) { out.push_back(std::move(v)); }
        return out;
    }
};

// fix-len key, collision risk in key
// freq-based not sort-based
