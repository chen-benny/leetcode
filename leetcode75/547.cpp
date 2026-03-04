#include <vector>

using std::vector;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = static_cast<int>(isConnected.size());
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ++count;
                dfs(isConnected, visited, i);
            }
        }

        return count;
    }

private:
    void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int curr) {
        visited[curr] = true;
        for (int adj = 0; adj < graph[curr].size(); adj++) {
            if (graph[curr][adj] == 1 && !visited[adj]) {
                dfs(graph, visited, adj);
            }
        }
    }
};

// follow-up: union-find

#include <numeric>

using std::iota;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = static_cast<int>(isConnected.size());
        vector<int> parent(n);
        vector<int> rank(n, 0);
        iota(parent.begin(), parent.end(), 0);
        int components = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    if (unite(parent, rank, i, j)) {
                        --components;
                    }
                }
            }
        }

        return components;
    }

private:
    int find(vector<int>& parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool unite(vector<int>& parent, vector<int>& rank, int a, int b) {
        int rootA = find(parent, a);
        int rootB = find(parent, b);
        if (rootA == rootB) { return false; }

        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            ++rank[rootA];
        }
        return true;
    }
};

