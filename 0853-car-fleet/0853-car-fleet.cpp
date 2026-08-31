class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // Store {position, speed}
        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort by position from closest to target to farthest
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double slowestTime = 0;

        for (auto& car : cars) {
            int pos = car.first;
            int spd = car.second;

            // Time to reach target
            double time = (double)(target - pos) / spd;

            // Cannot catch the fleet ahead
            if (time > slowestTime) {
                fleets++;
                slowestTime = time;
            }
        }

        return fleets;
    }
};