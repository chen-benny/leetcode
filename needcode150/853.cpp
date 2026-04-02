// sort + monotonic-state, T: O(nlogn), S: O(n)

#include <vector>
#include <algorithm>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = static_cast<int>(position.size());

        std::vector<std::pair<int, int>> cars(n);
        for (int i = 0; i < n; ++i) { cars[i] = {position[i], speed[i]}; }
        std::sort(cars.begin(), cars.end(), std::greater<>());

        int fleets = 0;
        double last = 0.0;

        for (auto& [pos, spd] : cars) {
            double arrival = static_cast<double>(target - pos) / spd;
            if (arrival > last) {
                last = arrival;
                ++fleets;
            }
        }
        return fleets;
    }
};

/*
   - sort decre by pos
   - double for arrival time
   - state over stack
   ? cars have the same pos
   ? car already at target
*/
