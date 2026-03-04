#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using std::vector:
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::pair;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < static_cast<int>(equations.size()); i++) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            graph[a].emplace_back(b, values[i]);
            graph[b].emplace_back(a, 1.0 / values[i]);
        }

        vector<double> result;
        result.reserve(queries.size());
        for (const auto& q : queries) {
            if (graph.find(q[0]) == graph.end() || graph.find(q[1]) == graph.end()) {
                result.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                result.push_back(dfs(graph, visited, q[0], q[1]));
            }
        }

        return result;
    }

private:
    double dfs(const unordered_map<string, vector<pair<string, double>>>& graph,
               unordered_set<string>& visited, const string& curr, const string& target) {
        if (curr == target) { return 1.0; }

        visited.insert(curr);

        for (const auto& [adj, weight] : graph.at(curr)) {
            if (visited.find(adj) == visited.end()) {
                double val = dfs(graph, visited, adj, target);
                if (val > 0) { return val * weight; }
            }
        }
        return -1.0;
    }
};

// follow-up: union-find

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = static_cast<int>(equations.size());
        
        for(int i = 0; i < n; i++) {
            add(equations[i][0]);
            add(equations[i][1]);
            unite(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> result;
        result.reserve(queries.size());

        for (const auto& q : queries) {
            if (parent.find(q[0]) == parent.end() || parent.find(q[1]) == parent.end()) {
                result.push_back(-1.0);
                continue;
            }
            auto [rootA, weightA] = find(q[0]);
            auto [rootB, weightB] = find(q[1]);
            result.push_back(rootA == rootB ? weightA / weightB : -1.0);
        }

        return result;
    }

private:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight; // weight[x] = x / parent[x]
    unordered_map<string, int> rank;

    void add(const string& x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            weight[x] = 1.0;
            rank[x] = 0;
        }
    }

    pair<string, double> find(const string& x) {
        string curr = x;
        double prod = 1;
        while (parent[curr] != curr) {
            weight[curr] *= weight[parent[curr]];
            parent[curr] = parent[parent[curr]];
            prod *= weight[curr];
            curr = parent[curr];
        }
        return {curr, prod};
    }

    void unite(const string& a, const string& b, double val) {
        auto [rootA, weightA] = find(a);
        auto [rootB, weightB] = find(b);

        if (rootA == rootB) { return; }

        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
            weight[rootA] = val * weightB / weightA;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
            weight[rootB] = weightA / (val * weightB);
        } else {
            parent[rootB] = rootA;
            weight[rootB] = weightA / (val * weightB);
            ++rank[rootA];
        }
    }
};
