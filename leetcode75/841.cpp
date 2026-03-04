#include <vector>

using std::vector;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = static_cast<int>(rooms.size());
        vector<bool> visited(n, false);
        int count = 0;

        dfs(rooms, visited, count, 0);

        return count == n;
    }

private:
    void dfs(const vector<vector<int>>& rooms, vector<bool>& visited, int& count, int curr) {
        visited[curr] = true;
        ++count;

        for (int adj : rooms[curr]) {
            if (!visited[adj]) {
                dfs(rooms, visited, count, adj);
            }
        }
    }
};

// follow-up: iter-dfs
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = static_cast<int>(rooms.size());
        vector<bool> visited(n, false);
        vector<int> stk;
        stk.reserve(n);
        stk.push_back(0);
        visited[0] = true;
        int count = 1;

        while (!stk.empty()) {
            int curr = stk.back();
            stk.pop_back();
            for (int adj : rooms[curr]) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    ++count;
                    stk.push_back(adj);
                }
            }
        }

        return count == n;
    }
};
