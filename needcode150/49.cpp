// freq-array as key, T: O(nk), S: O(nk)

#include <vector>
#include <string>
#include <unordered_map>
#include <cstring>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        constexpr int R = 26;
        constexpr char BASE = 'a';
        int freq[R];
        std::unordered_map<std::string, std::vector<std::string>> groups;
        groups.reserve(strs.size());
        groups.max_load_factor(0.25f);

        for (auto& s : strs) {
            std::memset(freq, 0, sizeof(freq)); // clear freq[] for each s
            for (char c : s) { freq[c-BASE]++; }
            // encode freq-array into fixed-length string key
            std::string key(R, '\0');
            for (int i = 0; i < R; i++) { key[i] = static_cast<char>(freq[i]); }
            groups[key].push_back(s);
        }

        std::vector<std::vector<std::string>> out;
        out.reserve(groups.size());
        for (auto& [k, v] : groups) { out.push_back(std::move(v)); }
        return out;
    }
};

// std::move(v): trans string own instead of copy
// key is 26 bytes, fits in one cache line, always L1, opt with absl::flat_hash_map
// sort_based key vs freq key: O(klogk) vs O(k) per word, strictly better, cheaper key than full str
// follow-up: std::array<uint8_t, 26> with custom hash
