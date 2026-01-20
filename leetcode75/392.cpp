class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
         * Return true if s is a sub seq of t
         *
         * Sub seq: formed by optional deleting chars from orig string
         * Two pointers: each char of s should be sequentially found in t
         */
        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.size();
    }
};

// follow-up: one-pointer
class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
         * Form: one traverse of t can make up s
         */
        if (s.empty()) {
            return true;
        }
        if (s.size() > t.size()) {
            return false;
        }

        int i = 0;
        for (char c : t) {
            if (s[i] == c && ++i == s.size()) {
                return true;
            }
        }

        return false;
    }
};
