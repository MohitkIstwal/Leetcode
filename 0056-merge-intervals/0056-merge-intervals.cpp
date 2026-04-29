class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end());
        int a = intervals[0][0], m = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= m) {
                m = max(m, intervals[i][1]);
            } else {
                v.push_back({a, m});
                a = intervals[i][0];
                m = intervals[i][1];
            }
        }
        v.push_back({a, m});
        return v;
    }
};
