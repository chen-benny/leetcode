#include <string>
#include <queue>

using std::string;
using std::queue;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;
        int n = senate.size();

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty()) {
            int rIdx = radiant.front();
            radiant.pop();
            int dIdx = dire.front();
            dire.pop();

            if (rIdx < dIdx) { // earlier senator bans the later on
                radiant.push(rIdx + n);
            } else {
                dire.push(dIdx + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};

// follow-up: single queue
class Solution {
public:
    string predictPartyVictory(string senate) {
        int radiantBans = 0;
        int direBans = 0;
        int radiantRemains = 0;
        int direRemains = 0;

        queue<char> q;
        for (char ch : senate) {
            q.push(ch);
            if (ch == 'R') {
                ++radiantRemains;
            } else {
                ++direRemains;
            }
        }

        while (q.size() > 1 && radiantRemains > 0 && direRemains > 0) {
            char ch = q.front();
            q.pop();

            if (ch == 'R') {
                if (radiantBans > 0) { // R is banned by prev R
                    --radiantBans;
                    --radiantRemains;
                } else { // R ban next D
                    ++direBans;
                    q.push(ch); // R survives, goes to next round
                }
            } else {
                if (direBans > 0) {
                    --direBans;
                    --direRemains;
                } else {
                    ++radiantBans;
                    q.push(ch);
                }
            }
        }

        return radiantRemains > 0 ? "Radiant" : "Dire";
    }
};
