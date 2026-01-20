class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        /*
         * Return the max num of op on nums[]
         *
         * op: pick two vals sum equals k and remove them
         * for val, find k - val in nums[] and remove
         * T: O(n)
         * S: O(n)
         */
        unordered_map<int, int> freq;
        int cnt = 0;

        for (int num : nums) {
            int need = k - num;

            if (freq[need] > 0) {
                cnt++;
                freq[need]--;
            } else {
                freq[num]++;
            }
        }

        return cnt;
    }
};

// follow-up: space O(1), better in practice, avoid overheading of hash-map
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        /*
         * Sort + two-pointers: try pair starting from max-val + min-val, then adjusting by sum-k
         */
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int cnt = 0;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) {
                cnt++;
                left++;
                right--;
            } else if (sum < k) {
                left++;
            } else {
                right--;
            }
        }

        return cnt;
    }
}
