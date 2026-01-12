class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        /**
         * Merge two strings alternatinly
         * 
         * One pointer traversing && build result string
         * Handles mismatch length
         * T: O(m + n)
         * S: O(m + n)
         */
        int m = word1.size();
        int n = word2.size();
        string res;
        res.reserve(m + n);

        int i = 0;
        while (i < m && i < n) {
            res += word1[i];
            res += word2[i];
            i++;
        }

        if (i < m) {
            res.append(word1, i, m - i);
        } else {
            res.append(word2, i, n - i);
        }

        return res;
    }
};
