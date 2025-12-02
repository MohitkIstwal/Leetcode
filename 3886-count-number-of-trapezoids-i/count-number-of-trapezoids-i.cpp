class Solution {
public:
    // create a map and store for how many points line on particular y axis
    // after that it is simply 3C2 which is n(n-1)/2
    // make sure to see overthrow int error
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> mp;
        for (int i = 0; i < points.size(); i++) {
            mp[points[i][1]]++;
        }
        int mod = 1e9 + 7;
        long long ans = 0, s = 0;
        for (auto it : mp) {
            long long t = (long long)(it.second * (it.second - 1)) / 2;
            ans += (t * s);
            s += t;
        }
        return (int)(ans % mod);
    }
};