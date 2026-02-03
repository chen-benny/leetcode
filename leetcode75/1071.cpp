class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        int len = gcd(m, n);

        string cand = str1.substr(0, len);
        if (canDivide(str1, cand) && canDivide(str2, cand)) {
            return cand;
        }
        return "";
    }

private:
    // Return true if t can divide s
    bool canDivide(string& s, string& t) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i % t.size()]) {
                return false;
            }
        }
        return true;
    }

    int gcd(int a, int b) {
        while (b) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};

// follow-up: pre-verify
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};
