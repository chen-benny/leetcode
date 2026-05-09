// min-heap of size k, T: O(nlog(k)), S: O(k)

#include <vector>
#include <queue>
#include <functional> // std::greater

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        /* pre allocate
        std::vector<int> buf;
        buf.reserve(k + 1);
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(
            std::greater<int>{}, std::move(buf));
        */
        for (int x : nums) {
            minHeap.push(x);
            if (static_cast<int>(minHeap.size()) > k) { minHeap.pop(); }
        }
        return minHeap.top();
    }
};

// counting-sort, T: O(n + R), R = value range, S: O(R) stack-allocated

#include <vector>
#include <cstring> // std::memset

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        constexpr int MIN = -10000;
        constexpr int MAX = 10000;
        constexpr int R = MAX - MIN + 1;

        int count[R];
        std::memset(count, 0, sizeof(count));
        for (int x : nums) { count[x - MIN]++; }

        for (int i = R - 1; i >= 0; --i) {
            k -= count[i];
            if (k <= 0) { return i + MIN; }
        }
        return -1;
    }
};

// quick-select with 3-way partition, T: O(n) avg, S: O(1)

#include <vector>
#include <algorithm> // std::swap, std::shuffle
#include <random> // std::mt19937, std::random_device
#include <utility> // std::pair

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        std::mt19937 rng(std::random_device{}());
        std::shuffle(nums.begin(), nums.end(), rng);

        int target = n - k;
        int lo = 0;
        int hi = n - 1;

        while (lo < hi) {
            auto [lt, gt] = partition3(nums, lo, hi);
            if (target < lt) { hi = lt - 1; }
            else if (target > gt) { lo = gt + 1; }
            else { break; }
        }
        return nums[target];
    }

private:
    std::pair<int, int> partition3(std::vector<int>& nums, int lo, int hi) {
        int pivot = nums[lo];
        int lt = lo;
        int gt = hi;
        int i = lo;
        while (i <= gt) {
            if (nums[i] < pivot) { std::swap(nums[i++], nums[lt++]); }
            else if (nums[i] > pivot) { std::swap(nums[i], nums[gt--]); }
            else { ++i; }
        }
        return {lt, gt};
    }
};

// three approaches win at: minHeap for k << n, couting-sort for small R, quick-select for k ~= n / 2 and memory constrained
// couting-sort cache: count[R] is 80KB, fit in L2, near-L1, single sequentail pass, SIMD vectorizable
// quick-select shuffle: worst case is sorted array hit O(n2), std::mt19937 + std::random_device guarantees O(n)
// three-way partition necessity: duplicate values common, two-way degrade to O(n2)
// minHeap pre-allocation: use priority_queue underlying vector
// streaming data: heap
// target = n - k for quick-select: partition into partial sorted order, k-th largest = (n-k) th smallest maps to 0-indexed
