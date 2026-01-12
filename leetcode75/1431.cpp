class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        /*
         * Return bool array where result[i] is true if candies[i] + extraCandies be the greatest among all candies
         * 
         * With extraCandies being the greatest among all: know max of candies and compare per each
         * T: O(n)
         * S: O(n)
         */
        int maxCandie = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        res.reserve(candies.size());

        for (int c : candies) {
            res.push_back(c + extraCandies >= maxCandie);
        }
        return res;
    }
};
