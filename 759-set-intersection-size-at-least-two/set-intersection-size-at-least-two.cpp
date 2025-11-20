class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b){ return a[1] < b[1]; });

        int x = -1, y = -1;
        int ans = 0;

        for (auto &in : intervals) {
            int l = in[0], r = in[1];
            int need = 2;

            if (y >= l && y <= r) need--;
            if (x >= l && x <= r) need--;

            if (need == 2) {
                x = r - 1;
                y = r;
                ans += 2;
            }
            else if (need == 1) {
                if (y != r) {
                    x = y;
                    y = r;
                } else {
                    x = r - 1;
                }
                ans += 1;
            }
        }

        return ans;
    }
};
