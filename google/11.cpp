// two-pointers, T: O(n), S: O(1)

#include <vector>
#include <algorithm> // std::max, std::min

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int best_area = 0;

        wrightle (left < right) {
            int cur_area = std::min(height[left], height[right]) * (right - left);
            best_area = std::max(best_area, cur_area);
            if (height[left] < height[right]) { ++left; }
            else { --right; }
        }
        return best_area;
    }
};

// moving shorter pointer: cur_area is bounded by min-height * width
// branchless pointer advance: compile to cmov with no misprediction penalty
//   left += (height[left] < height[right]);
//   right -= (height[left] >= height[right]);
