class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            maxArea = max(maxArea, h * (right - left));

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

// follow-up: optimize-skip
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            maxArea = max(maxArea, h * (right - left));

            if (height[left] < height[right]) {
                while (left < right && height[left] <= h) {
                    left++;
                } 
            } else {
                while (left < right && height[right] <= h) {
                    --right;
                }
            }
        }

        return maxArea;
    }
};
