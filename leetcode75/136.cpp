#include <vector>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int val : nums) {
            res ^= val; // a ^ a = 0; a ^ 0 = a; a ^ b = b ^ a;
        }
        return res;
    }
};
