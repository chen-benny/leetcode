// hash-map + binary-search, T: O(log(n)) get, O(1) set, S: O(1)

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class TimeMap {
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
        auto pos = std::upper_bound(vec.begin(), vec.end(), timestamp, // find the 1st elem gt given timestamp
                                   [](int t, const Entry& e) { return t < e.first; });
        if (pos == vec.begin()) { return ""; }
        return std::prev(pos)->second;
    }

private:
    using Entry = std::pair<int, std::string>;
    using Bucket = std::vector<Entry>;
    std::unordered_map<std::string, Bucket> store;
};

/*
   - upper_bound
   - strictly incre timestamp
   - cache behavior
   - string key overhead
   ? reserve store but not vector
   ? timestamp not strictly incre
*/
