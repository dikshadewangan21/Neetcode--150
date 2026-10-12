class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
                sort(intervals.begin(), intervals.end());

        // Store {query value, original index}
        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        // Min heap: {interval length, interval right endpoint}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> ans(queries.size(), -1);
        int i = 0;

        for (auto [x, idx] : q) {

            // Add intervals that start before or at x
            while (i < intervals.size() &&
                   intervals[i][0] <= x) {
                
                int left = intervals[i][0];
                int right = intervals[i][1];
                int len = right - left + 1;

                pq.push({len, right});
                i++;
            }

            // Remove intervals that do not contain x
            while (!pq.empty() && pq.top().second < x) {
                pq.pop();
            }

            // The smallest valid interval is at the top
            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }

        return ans;

        
    }
};