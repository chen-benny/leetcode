class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[write++] = nums[i];
            }
        }

        while (write < n) {
            nums[write++] = 0;
        }
    }
};

// follow-up: swap-based
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[write++], nums[i]);
            }
        }
    }
};
