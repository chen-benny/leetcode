// one-pass, track-extremity, T: O(n), S: O(1)

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min_price = INT_MAX;
        int best = 0;

        for (int price : prices) {
            min_price = std::min(min_price, price);
            best = std::max(best, price - min_price);
        }
        return best;
    }
};

/*
   - best = 0 over not INT_MIN
   - Kadane's connection
   ? without std::min/std::max
*/
