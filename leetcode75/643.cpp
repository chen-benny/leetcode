class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int winSum = 0;
        for (int i = 0; i < k; i++) {
            winSum += nums[i];
        }

        int maxSum = winSum;
        for (int i = k; i < nums.size(); i++) {
            // winSum += nums[i] - nums[i-k]; // sequentail dependency
            winSum += nums[i];
            winSum -= nums[i-k]; // parallel memory access optmization
            maxSum = max(maxSum, winSum);
        }

        return (double)maxSum / k;
    }
};
