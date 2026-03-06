#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = static_cast<int>(spells.size());
        int m = static_cast<int>(potions.size());
        sort(potions.begin(), potions.end());

        vector<int> result;
        result.reserve(n);
        for (int spell : spells) {
            int lo = 0;
            int hi = m - 1;
            int pos = m; // default: no potion works

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (static_cast<long long>(spell) * potions[mid] >= success) {
                    pos = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            result.push_back(m - pos);
        }

        return result;
    }
};
