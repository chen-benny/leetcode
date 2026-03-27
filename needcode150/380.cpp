// hash-map + daynamic-array, T: O(1) avg all ops, S: O(n)
// array for O(1) indexed random access, map for O(1) val -> idx lookup
// delete by swapping target with last elem, avoid O(n) shift

#include <vector>
#include <unordered_map>
#include <random>

class RandomizedSet {
    std::vector<int> vals;
    std::unordered_map<int, int> idx; // val -> idx
    std::mt19937 rng{std::random_device{}()};

public:
    RandomizedSet() {
        idx.reserve(128);
        idx.max_load_factor(0.25f);
    }

    bool insert(int val) {
        if (idx.count(val)) { return false; }
        idx[val] = static_cast<int>(vals.size());
        vals.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = idx.find(val);
        if (it == idx.end()) { return false; }

        int pos = it->second;
        int last = vals.back();

        // swap target with last element
        vals[pos] = last;
        idx[last] = pos;
        vals.pop_back();
        idx.erase(it);
        return true;
    }

    int getRandom() {
        // int randIdx = rand() % vals.size();
        // return vals[randIdx];
        std::uniform_int_distribution<int> dist(
                0, static_cast<int>(vals.size()) - 1);
        return vals[dist(rng)];
    }
};

/*
   - why swap with last for delete
   - edge case: delete the last elem
   - std::mt19937 vs std::rand
   - cache behavior
   ? why swap with last preserve uniform distribution for getRandom
   ? dup inserts allowed
   ? make getRandom worst cast not just avg
*/
