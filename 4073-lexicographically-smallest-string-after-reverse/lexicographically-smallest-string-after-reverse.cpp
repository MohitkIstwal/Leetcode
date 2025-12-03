class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string ans = s,temp=s;

        for (int k = 1; k <= n; k++) {
                temp = s;
                reverse(temp.begin(), temp.begin() + k);
                ans = min(ans, temp);
            
                temp = s;
                reverse(temp.end() - k, temp.end());
                ans = min(ans, temp);
            }

        return ans;
    }
};
