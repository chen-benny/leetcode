// binary-search on answer, T: O(nlog(m)), S: O(1)

#include <vector>
#include <algorithm> // std::max_element

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int lo = 1;
        int hi = *std::max_element(piles.begin(), piles.end());

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (can_finish(piles, h, mid)) { hi = mid; }
            else { lo = mid + 1; }
        }
        return lo;
    }

private:
    bool can_finish(std::vector<int>& piles, int h, int speed) {
        long long hours = 0;
        for (int p : piles) {
            hours += (p + speed - 1) / speed; // ceil(p / speed)
        }
        return hours <= h;
    }
};

// ceiling division without std::ceil: (x + d - 1) / d is pure integer arithmetic
// long long for hours: h <= 1e9 (piles[i] = 1e9. speed = 1)
// lo < hi termination: hi = mid, mid itself should be included
