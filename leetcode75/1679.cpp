class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
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
