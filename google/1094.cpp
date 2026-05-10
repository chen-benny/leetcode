// sweep-line, T: O(nlogn), S: O(n)

#include <vector>
#include <algorithm>
#include <utility>

class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
        std::vector<std::pair<int,int>> events;
        events.reserve(trips.size() * 2);

        for (auto& t : trips) {
            events.push_back({t[1], t[0]}); // pickup
            events.push_back({t[2], -t[0]}); // dropoff
        }

        // sort by stop, dropoff before pickup
        std::sort(events.begin(), events.end(), [](const std::pair<int,int>& a,
                                                   const std::pair<int,int>& b) {
            return a.first != b.first ? a.first < b.first : a.second < b.second;
        });

        int curr = 0;
        for (auto& [stop, delta] : events) {
            curr += delta;
            if (curr > capacity) { return false; }
        }
        return true;
    }
};


// difference-array, T: O(n + R), R = max stop, S: O(R) stack-allocated

#include <vector>
#include <cstring> // std::memset

class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
        constexpr int R = 1001;
        int diff[R];
        std::memset(diff, 0, sizeof(diff));

        for (auto& t : trips) {
            diff[t[1]] += t[0]; // pickup
            diff[t[2]] -= t[0]; // dropoff
        }

        int curr = 0;
        for (int i = 0; i < R; ++i) {
            curr += diff[i];
            if (curr > capacity) { return false; }
        }
        return true;
    }
};

// difference-array over sweep-line: sorting cost, bounded range, 1e9 stops leads to 4GB array
// why pickup first then dropoff for sweep-line: ensure capacity triggers correctly
