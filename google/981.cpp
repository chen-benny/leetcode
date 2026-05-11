// hash-map + binary-search, T: O(logn) get, O(1) set, S: O(n)

#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

class TimeMap {
private:
    using Entry = std::pair<int, std::string>;
    using Bucket = std::vector<Entry>;
    std::unordered_map<std::string, Bucket> store;

public:
    TimeMap() {
        store.reserve(128);
        store.max_load_factor(0.25f);
    }

    void set(std::string key, std::string value, int timestamp) {
        store[key].push_back({timestamp, std::move(value)});
    }

    std::string get(std::string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) { return ""; }

        auto& vec = it->second;
        int lo =0;
        int hi = static_cast<int>(vec.size()) - 1;
        int res = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (vec[mid].first <= timestamp) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res == -1 ? "" : vec[res].second;
    }
};
