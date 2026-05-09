// min-heap of size k. T: O(nlog(k)), S: O(n)

#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <functional>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq; // val: cnt
        freq.reserve(nums.size());
        freq.max_load_factor(0.25f);
        for (int x : nums) { freq[x]++; }

        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<>> minHeap;

        for (auto& [val, cnt] : freq) {
            minHeap.push({cnt, val});
            if (static_cast<int>(minHeap.size()) > k) { minHeap.pop(); }
        }

        std::vector<int> out;
        out.reserve(k);
        while (!minHeap.empty()) {
            out.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return out;
    }
};

// bucket-sort + val-index array, T: O(n), S: O(n)

#include <vector>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());

        constexpr int MIN = -10000;
        constexpr int MAX = 10000;
        constexpr int R = MAX - MIN + 1;
        std::vector<int> freq(R); // val: cnt
        for (int x : nums) { freq[x - MIN]++; }
        
        std::vector<std::vector<int>> bucket(n + 1);
        for (int i = 0; i < R; ++i) {
            if (freq[i] != 0) { bucket[freq[i]].push_back(i + MIN); }
        }

        std::vector<int> out;
        out.reserve(k);
        for (int i = n; i >= 1 && static_cast<int>(out.size()) < k; --i) {
            for (int val : bucket[i]) { out.push_back(val); }
        }
        return out;
    }
};

// quick-select with 3-way partition, T: O(n) avg, S: O(n)

#include <vector>
#include <unordered_map>
#include <algorithm> // std::swap, std::shuffle
#include <random> // std::m19937, std::random_device
#include <utility>
#include <functional>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        freq.reserve(nums.size());
        freq.max_load_factor(0.25f);
        for (int x : nums) { freq[x]++; }

        std::vector<std::pair<int, int>> entries;
        entries.reserve(freq.size());
        for (auto& [val, cnt] : freq) { entries.push_back({cnt, val}); }

        std::mt19937 rng(std::random_device{}());
        std::shuffle(entries.begin(), entries.end(), rng);

        int n = static_cast<int>(entries.size());
        int target = n - k;
        int lo = 0;
        int hi = n - 1;

        while (lo < hi) {
            auto [lt, gt] = partition3(entries, lo, hi);
            if (target > gt) { lo = gt + 1; }
            else if (target < lt) { hi = lt - 1; }
            else { break; }
        }

        std::vector<int> out;
        out.reserve(k);
        for (int i = target; i < n; ++i) { out.push_back(entries[i].second); }
        return out;
    }

private:
    std::pair<int, int> partition3(std::vector<std::pair<int, int>>& entries, int lo, int hi) {
        int pivot = entries[lo].first;
        int lt = lo;
        int gt = hi;
        int i = lo;
        while (i <= gt) {
            if (entries[i].first < pivot) { std::swap(entries[i++], entries[lt++]); }
            else if (entries[i].first > pivot) { std::swap(entries[i], entries[gt--]); }
            else { ++i; }
        }
        return {lt, gt};
    }
};

// three approaches win at: minHeap for k << n, bucket allocates O(n) innner vectors, introducing heap-fragment and pointer-chasing
//   quick-select: in-place on entries array, no heap allocation
//  entries pre-allocated
// std::move into out: for heavier payload (e.g. strings, structs), use std::move(entries[i].second)
// bucket inner vector fragmentation: std::vector<std::vector<int>> bucket(n + 1), each inner vector is separated heap allocation
