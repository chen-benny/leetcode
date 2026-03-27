// prefix-sum + linear-scan, T: O(n) pick, S: O(n)

#include <vector>
#include <cstdlib>
#include <numeric>

class Solution {
    std::vector<int> prefix;
    int total;

public:
    Solution(std::vector<int>& w) {
        prefix.resize(w.size());
        std::partial_sum(w.begin(), w.end(), prefix.begin());
        total = prefix.back();
    }

    int pickIndex() {
        int r = std::rand() % total + 1;
        for (int i = 0; i < static_cast<int>(prefix.size()); i++) {
            if (prefix[i] >= r) { return i; }
        }
        return -1;
    }
};

// prefix-sum + binary-search, T: O(logn) pick, S: O(n)

#include <vector>
#include <cstdlib>
#include <numeric>
#include <algorithm>

class Solution {
    std::vector<int> prefix;
    int total;

public:
    Solution(std::vector<int>& w) {
        prefix.resize(w.size());
        std::partial_sum(w.begin(), w.end(), prefix.begin());
        total = prefix.back();
    }

    int pickIndex() {
        int r = std::rand() % total + 1;
        return static_cast<int>(
            std::lower_bound(prefix.begin(), prefix.end(), r) - prefix.begin()
        );
    }
};

/*
   - why prefix sum encodes weight
   - std::partial_sum vs manual loop
   - lower_bound correctness
   - cache behavior
   ? why rand() % total + 1 over rand() % total
   ? floating-point weights
   ? O(1) pick
*/
