class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int, int> mp;

        for (int a = 1; a * a * a <= n; a++) {
            for (int b = a; a * a * a + b * b * b <= n; b++) {
                int x = a * a * a + b * b * b;
                mp[x]++;
            }
        }

        vector<int> ans;
        for (auto &it : mp) {
            if (it.second >= 2) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};