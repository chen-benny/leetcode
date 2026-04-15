// greedy + two-heaps, T: O(nlogn + klogn), S: O(n)

#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        int n = static_cast<int>(profits.size());

        // min-heap by capital requirement
        std::vector<std::pair<int, int>> projects(n);
        for (int i = 0; i < n; ++i) { projects[i] = {capital[i], profits[i]}; }
        std::sort(projects.begin(), projects.end());

        std::priority_queue<int> maxHeap;
        int idx = 0;

        for (int i = 0; i < k; ++i) {
            while (idx < n && projects[idx].first <= w) {
                maxHeap.push(projects[idx++].second);
            }
            if (maxHeap.empty()) { break; }
            w += maxHeap.top(); maxHeap.pop();
        }
        return w;
    }
};

// greedy correctness
// sort + pointer vs min-heap
// early exit on empty
// cache behavior
// k > n?
