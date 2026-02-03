class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandie = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        res.reserve(candies.size());

        for (int c : candies) {
            res.push_back(c + extraCandies >= maxCandie);
        }
        return res;
    }
};
