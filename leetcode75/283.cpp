class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
         * Move all 0's to the end while keep order of non-zero elements
         *
         * Two pointers: read skip non-0; write in-place behind read
         * Fill in left with 0
         * T: O(n)
         * S: O(1)
         */
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
        /*
         * read non-0, swap write and read
         * non-0 is awalys write behind in array
         */
        int write = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[write++], nums[i]);
            }
        }
    }
};
