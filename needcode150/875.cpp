// binary search on answer, T: O(n * log(m)) - m: max(piles), S: O(1)

#include <vector>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int lo = 1;
        int hi = *std::max_element(piles.begin(), piles.end());

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid; // ceil(p/mid)
            }
            if (h >= hours) { hi = mid; }
            else { lo = mid + 1; }
        }
        return lo;
    }
};

/*
   - ceiling division without std::ceil
   - monotone property
   - cache behavior
   ? hi = max(piles) not sum(piles)
   ? integer overflow on hours
*/
