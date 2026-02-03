class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            ++freq[num];
        }

        unordered_set<int> seen;
        for (auto& [num, cnt] : freq) {
            if (seen.count(cnt)) {
                return false;
            }
            seen.insert(cnt);
        }

        return true;
    }
};
