class Solution {
public:
    int xorAfterQueries(vector<int>& v, vector<vector<int>>& q) {
        int mod = 1e9 + 7;

        for (auto &v1 : q) {
            int si = v1[0], ei = v1[1];
            int inc = v1[2], mul = v1[3];

            for (int j = si; j <= ei; j += inc) {
                long long ans = 1LL * v[j] * mul;
                v[j] = ans % mod;
            }
        }

        int fans = 0;
        for (auto val : v) {
            fans ^= val;
        }

        return fans;
    }
};