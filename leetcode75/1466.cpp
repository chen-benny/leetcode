#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> graph(n);
        for (const auto& edge : connections) {
            graph[edge[0]].emplace_back(edge[1], true);
            graph[edge[1]].emplace_back(edge[0], false);
        }

        vector<bool> visited(n, false);
        int count = 0;
        dfs(graph, visited, count, 0);
        return count;
    }

private:
    void dfs(const vector<vector<pair<int, bool>>>& graph, vector<bool>& visited, int& count, int curr) {
        visited[curr] = true;
        for (const auto& [adj, isOrig] : graph[curr]) {
            if (!visited[adj]) {
                if (isOrig) { ++count; }

                dfs(graph, visited, count, adj);
            }
        }
    }
};

// follow-up: iter-dfs

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> graph(n);
        for (const auto& edge : connections) {
            graph[edge[0]].emplace_back(edge[1], true);
            graph[edge[1]].emplace_back(edge[0], false);
        }

        vector<bool> visited(n, false);
        vector<int> stk;
        stk.reserve(n);
        stk.push_back(0);
        visited[0] = true;
        int count = 0;

        while (!stk.empty()) {
            int curr = stk.back();
            stk.pop_back();

            for (const auto& [adj, isOrig] : graph[curr]) {
                if (!visited[adj]) {
                    visited[adj] = true;

                    if (isOrig) { ++count; }

                    stk.push_back(adj);
                }
            }
        }

        return count;
    }
};
