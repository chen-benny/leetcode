// Bellman-Ford, T: O(kE), S: O(V)

#include <vector>
#include <algorithm> // std::min
#include <climits> // INT_MAX
#include <utility> // std::swap

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights,
                          int src, int dst, int k) {
        std::vector<int> cost(n, INT_MAX);
        std::vector<int> tmp(n);
        cost[src] = 0;

        for (int i = 0; i <= k; ++i) {
            tmp = cost; // deep copy
            for (auto& f : flights) {
                int u = f[0];
                int v = f[1];
                int wt = f[2];
                if (cost[u] == INT_MAX) { continue; }
                tmp[v] = std::min(tmp[v], cost[u] + wt);
            }
            std::swap(cost, tmp); // O(1) pointer swap, no allocation
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};

// Dijkstra with stop count, T: O(ElogV), S: O(V+E)

#include <vector>
#include <queue> // std::priority_queue
#include <climits> // INT_MAX
#include <utility> // std::pair
#include <tuple>

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights,
                          int src, int dst, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n); // adj-list: to: [(from, wt),]
        for (auto& f : flights) { adj[f[0]].push_back({f[1], f[2]}); }

        std::priority_queue<std::tuple<int, int, int>,
                            std::vector<std::tuple<int, int, int>>,
                            std::greater<>> pq; // {cost, cur, stops}
        pq.push({0, src, 0});
        std::vector<int> stops(n, INT_MAX);

        while (!pq.empty()) {
            auto [cost, cur, stop] = pq.top();
            pq.pop();

            if (cur == dst) { return cost; }
            if (stop > k) { continue; }
            if (stops[cur] <= stop) { continue; } // pruning
            stops[cur] = stop;

            for (auto& [next, wt] : adj[cur]) {
                pq.push({cost + wt, next, stop + 1});
            }
        }
        return -1;
    }
};

// Bellman-Fort snapshot cost: a single iteration shouldn't chain further nodes
// i <= k: k stops = k + 1 edges 
// Dijkstra stop pruning at stops[cur] <= stop: only path with more stops can yield lower cost
// Bellman-Ford vs Dijkstra: Bellman-Ford handles negative weights wins when small k and large E, while Dijkstra better for dense graph
// Bellman-Ford has better cache behavior: sequentail scan, stride-1 and prefetcher friendly
