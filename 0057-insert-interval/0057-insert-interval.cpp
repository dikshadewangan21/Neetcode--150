class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                                vector<int>& newInterval) {

        vector<vector<int>> result;

        int i = 0;
        int start = newInterval[0];
        int end = newInterval[1];

        // 1. Add intervals before newInterval
        while (i < intervals.size() && intervals[i][1] < start) {
            result.push_back(intervals[i]);
            i++;
        }

        // 2. Merge overlapping intervals
        while (i < intervals.size() && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }

        // 3. Add new/merged interval
        result.push_back({start, end});

        // 4. Add remaining intervals
        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};