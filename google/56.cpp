// sort + linear merge, T: O(nlogn), S: O(1)

#include <vector>
#include <algorithm> // std::sort

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> out;
        out.reserve(intervals.size());

        for (auto& iv : intervals) {
            if (!out.empty() && iv[0] <= out.back()[1]) {
                out.back()[1] = std::max(out.back()[1], iv[1]);
            } else {
                out.push_back(iv); // out.push_back(std::move(iv))
            }
        }
        return out;
    }
};

// sort by start: [start, end], starts first then end, lexicographically
// in-place merge: only push_back on non-overlapping intervals
// out.reserve(intervals.size()): worst case
// sort by start over end: guarantee all intervals that could overlap are adjacent

