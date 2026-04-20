class Solution {
public:
    int maxDistance(vector<int>& c) {
        int n = c.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(c[i] != c[n - 1]) {
                ans = max(ans, n - 1 - i);
                break;
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            if(c[i] != c[0]) {
                ans = max(ans, i);
                break;
            }
        }

        return ans;
    }
};