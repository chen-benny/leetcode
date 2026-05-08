// dfs cycle-detection, T: O(V+E), S: O(V+E)

#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses); // adj-list
        for (auto& p : prerequisites) { adj[p[1]].push_back(p[0]); } // (0, 1) means 1 -> 0

        std::vector<int> state(numCourses, 0); // 0=un-seen, 1=in-prog, 2=done

        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0 && has_cycle(adj, state, i)) { return false; }
        }
        return true;
    }

private:
    bool has_cycle(std::vector<std::vector<int>>& adj,
                   std::vector<int>& state, int cur) {
        state[cur] = 1;
        for (int next : adj[cur]) {
            if (state[next] == 1) { return true; } // back edge found: has cycle
            if (state[next] == 0 && has_cycle(adj, state, next)) { return true; }
        }
        state[cur] = 2;
        return false;
    }
};

// topological-sort / Kahn's Algorithm, bfs from nodes with in-degree 0, T: O(V+E), S: O(V+E)

#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) { q.push(i); }
        }

        int done = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ++done;
            for (int next : adj[cur]) {
                if (--indegree[next] == 0) { q.push(next); }
            }
        }
        return done == numCourses;
    }
};

// dfs three-state vs two-state: three-state distinguishes "on-stack" vs "explored"
// Kahn' Alogrithm: cycle detect via count
// adjacency list vs matrix: sparse graph, O(V+E) vs O(V2)
// Kahn's vs dfs: able to gen path
