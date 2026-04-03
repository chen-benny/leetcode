// binary-search on flat index, T: O(log(mn)), S: O(1)

#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        int lo = 0;
        int hi = m * n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = matrix[mid / n][mid % n];

            if (val == target) { return true; }
            else if (val < target) { lo = mid + 1; }
            else { hi = mid - 1; }
        }
        return false;
    }
};

/*
   - mid / n, mid % n
   - why not two separate binary search
   - cache behavior
   ? overflow on m * n
   ? one row or one col matrix
*/
