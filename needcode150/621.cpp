// greedy math, T: O(n), S: O(1)

#include <vector>
#include <algorithm>
#include <cstring>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        constexpr int ALPHA_SIZE = 26;
        constexpr char BASE_CHAR = 'A';

        int freq[ALPHA_SIZE];
        std::memset(freq, 0, sizeof(freq));
        for (char c : tasks) { freq[c - BASE_CHAR]++; }

        int maxFreq = *std::max_element(freq, freq + ALPHA_SIZE);
        int maxCount = 0;
        for (int i = 0; i < ALPHA_SIZE; ++i) {
            if (freq[i] == maxFreq) { ++maxCount; }
        }

        int minCycles = (maxFreq - 1) * (n + 1) + maxCount;
        return std::max(minCycles, static_cast<int>(tasks.size()));
    }
};

// formula derivation
// std::max_element on flat array
// maxCount
// std::max(minCycles, tasks.size())
// cache behavior
// tasks.size() serve as lower bound
// n = 0?
