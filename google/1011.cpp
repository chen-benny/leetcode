// binary-search on answer, T: O(nlog(sum-max)), S: O(1)

#include <vector>
#include <numeric> // std::accumulate
#include <algorithm> // std::max_element

class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        int lo = *std::max_element(weights.begin(), weights.end());
        int hi = std::accumulate(weights.begin(), weights.end(), 0);

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (can_ship(weights, days, mid)) { hi = mid; }
            else { lo = mid + 1; }
        }
        return lo;
    }

private:
    bool can_ship(std::vector<int>& weights, int days, int capacity) {
        int used_days = 1;
        int loaded = 0;
        for (int w : weights) {
            if (loaded + w > capacity) {
                ++used_days;
                loaded = 0;
            }
            loaded += w;
        }
        return used_days <= days;
    }
};
