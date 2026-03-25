// hash-set, T: O(n), S: O(n)

#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> seen(nums.begin(), nums.end());
        int maxLen = 0;

        for (int x : seen) {
            if (seen.count(x - 1)) { continue; } // not a seq head

            int len = 1;
            while (seen.count(x + len)) { ++len; }
            maxLen = std::max(maxLen, len);
        }
        return maxLen;
    }
};

// union-find, union each num with num + 1, track component size, O(a(n)), S: O(n)

#include <vector>
#include <unordered_map>

class Solution {
    struct UnionFind {
        std::unordered_map<int, int> parent;
        std::unordered_map<int, int> rank;
        std::unordered_map<int, int> size;

        void add(int x) {
            if (parent.count(x)) { return; }
            parent[x] = x;
            rank[x] = 0;
            size[x] = 1;
        }

        int find(int x) { // path compression
            if (parent[x] != x) { parent[x] = find(parent[x]); }
            return parent[x];
        }

        void unite(int a, int b) { // union by rank
            a = find(a);
            b = find(b);
            if (a == b) { return; }

            if (rank[a] < rank[b]) { std::swap(a, b); }
            parent[b] = a;
            size[a] += size[b];
            if (rank[a] == rank[b]) { rank[a]++; }
        }

        int getSize(int x) { return size[find(x)]; }
    };

public:
    int longestConsecutive(std::vector<int>& nums) {
        UnionFind uf;
        for (int x : nums) { uf.add(x); }
        for (int x : nums) {
            if (uf.parent.count(x + 1)) { uf.unite(x, x + 1); }
        }

        int maxLen = 0;
        for (int x : nums) { maxLen = std::max(maxLen, uf.getSize(x)); }
        return maxLen;
    }
};

/*
   - cache behavior
   ? iter over seen
   ? when does union find win
   ? does duplicate break the hash-set approatch
   ? what if the array is nearly sorted
