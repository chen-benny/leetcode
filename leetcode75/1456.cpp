class Solution {
public:
    int maxVowels(string s, int k) {
        bool vowels[128] = {};
        vowels['a'] = vowels['e'] = vowels['i'] = vowels['o'] = vowels['u'] = true;

        int winCnt = 0;
        for (int i = 0; i < k; i++) {
            if (vowels[s[i]]) {
                winCnt++;
            }
        }

        int maxCnt = winCnt;
        for (int i = k; i < s.size(); i++) {
            if (vowels[s[i]]) {
                winCnt++;
            }
            if (vowels[s[i - k]]) {
                winCnt--;
            }
            maxCnt = max(maxCnt, winCnt);
            if (maxCnt == k) { // early exit
                return k;
            }
        }

        return maxCnt;
    }
};
