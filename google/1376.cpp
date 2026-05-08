// dfs, T: O(n), S: O(n)

#include <vector>
#include <algorithm> // std::max

class Solution {
public:
    int numOfMinutes(int n, int headID, std::vector<int>& manager,
                     std::vector<int>& informTime) {
        std::vector<std::vector<int>> adj(n); // adj-list
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) { adj[manager[i]].push_back(i); }
        }
        return dfs(adj, informTime, headID);
    }

private:
    int dfs(std::vector<std::vector<int>>& adj,
            std::vector<int>& informTime, int cur) {
        int maxTime = 0;
        for (int sub : adj[cur]) {
            maxTime = std::max(maxTime, dfs(adj, informTime, sub));
        }
        return informTime[cur] + maxTime;
    }
};

// stack iterative dfs, T: O(n), S: O(n)

#include <vector>
#include <stack>
#include <algorithm> // std::max
#include <utility> // std::pair

class Solution {
public:
    int numOfMinutes(int n, int headID, std::vector<int>& manager,
                     std::vector<int>& informTime) {
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) { adj[manager[i]].push_back(i); }
        }

        std::stack<std::pair<int, int>> stk; // {cur, acc_time}
        stk.push({headID, informTime[headID]});
        int maxTime = 0;

        while (!stk.empty()) {
            auto [cur, time] = stk.top();
            stk.pop();
            maxTime = std::max(maxTime, time);
            for (int sub : adj[cur]) {
                stk.push({sub, time + informTime[sub]});
            }
        }
        return maxTime;
    }
};

// tree not graph, no visited array: no cycle exist
// informTime[cur] + maxTime: sub return cur time + max below the tree
// adjacency list direction: mgr -> sub
// stack depth dfs: tree height for O(n) worst case for a linear chain, overflow for n = 10^5
// adj-list is a separate heap-allocated vector: good for wide tree, bad for deep tree (pointer chasing between levels)
// bfs alternative
// multiple roots (forest): iterate roots
