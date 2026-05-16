// min-heap of size k, T: O(nlogk), S: O(n)

#include <vector>
#include <unordered_map>
#include <queue> // std::priority_queue
#include <utility> // std::pair
#include <functional> // std::greater

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        freq.reserve(nums.size());
        freq.max_load_factor(0.25f);
        for (int val : nums) { freq[val]++; }

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

// bucket-sort, freq is bounded by [1, n], idx as freq buckets, T: O(n), S: O(n)

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        std::unordered_map<int, int> freq; // {val: cnt} of nums[]
        freq.reserve(nums.size());
        freq.max_load_factor(0.25f);
        for (int val : nums) { freq[val]++; }

        std::vector<std::vector<int>> bucket(n + 1); // bucket[i] = vals with cnt of i
        for (auto& [val, cnt] : freq) { bucket[cnt].push_back(val); }

        std::vector<int> out;
        out.reserve(k);
        for (int i = n ; i >= 1 && static_cast<int>(out.size()) < k; i--) {
            for (int val : bucket[i]) {
                out.push_back(val);
            }
        }
        return out;
    }
};


// quick-select with 3-way partition, T: O(n) avg, S: O(n)

#include <vector>
#include <unordered_map>
#include <algorithm> // std::swap, std::shuffle
#include <random> // std::mt19937, std::random_device
#include <utility> // std::pair

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
            if (target < lt) { hi = lt - 1; }
            else if (target > gt) { lo = gt + 1; }
            else { break; }
        }

        std::vector<int> out;
        out.reserve(k);
        for (int i = target; i < n; i++) { out.push_back(entries[i].second); }
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
            else { i++; }
        }
        return {lt, gt};
    }
};

// heap vs bucket vs quick-select: heap for k << n; bucket for O(n) with inner vec sep heap alloc; quick-select for O(n) space adv
// shuffle before quick-select, mandatory: adversarial freq dist hit O(n2)
// 3-way partition: handles duplicate freq
// double-buf in bucket: inner vec grow dynamic, CSR layout (flat + offset arr) eliminate inner vec heap alloc
