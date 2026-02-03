class Solution {
public:
    string reverseVowels(string s) {
        static bool v[128] = {false};
        v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = true;
        v['A'] = v['E'] = v['I'] = v['O'] = v['U'] = true;

        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (l < r && !v[s[l]]) {
                l++;
            }
            while (l < r && !v[s[r]]) {
                r--;
            }
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};

// alter: string::find
class Solution {
public:
    string reverseVowels(string s) {
        string v = "aeiouAEIOU";
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (l < r && v.find(s[l]) == string::npos) {
                l++;
            }
            while (l < r && v.find(s[r]) == string::npos) {
                r--;
            }
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};
