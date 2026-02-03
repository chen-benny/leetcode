class Solution {
public:
    bool isSubsequence(string s, string t) {
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
