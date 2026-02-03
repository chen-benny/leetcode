class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int read = 0;

        while (read < n) {
            char cur = chars[read];
            int cnt = 0;

            while (read < n && chars[read] == cur) {
                read++;
                cnt++;
            }

            chars[write++] = cur;
            if (cnt > 1) {
                string d = to_string(cnt);
                for (char c : d) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};
